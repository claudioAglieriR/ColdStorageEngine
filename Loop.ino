void loop() {
  
  WiFiClient client;
  FirebaseJson updateData;

  timestamp = getTimestamp();
  tempsens = dht.readTemperature();
  int i = 0;
  
  Firebase.begin(FIREBASEDATO_HOST,FIREBASEDATO_AUTH);

  if (Firebase.getDouble(firebaseDatadato,"/main/temp")){
    tempdata = firebaseDatadato.doubleData()-273.15;
  }
  else{
     Serial.println(firebaseDatadato.errorReason());
  }

  tempext = (tempsens+tempdata)/2;

//Data elaboration

  if (tempint<4){
          
      state = 0;
      digitalWrite(LED, !state);
      Serial.println("Engine OFF");
      
      tempint = tempint +(0.0001*(tempext-tempint))*tempoff;
        
   } else if (tempint>8){
    
      state = 1;
      digitalWrite(LED, !state);
      Serial.println("Engine ON");

      tempint = tempint - (0.4*tempon);
                
   } else { 
      
      if(state == 0){
        
        Serial.println("Engine OFF");
        
        tempint = tempint + (0.0001*(tempext-tempint))*tempoff;

      }
      
      else {
        
        Serial.println("Engine ON");
        
        tempint = tempint - (0.4*tempon);
        
      }  
    }   

//Upload and download data - Firebase

      Firebase.begin(FIREBASE_HOST,FIREBASE_AUTH);

      if(timestamp!=""){
          updateData.set("timestamp", timestamp);
          updateData.set("tempsens", tempsens);
          updateData.set("tempdata", tempdata);
          updateData.set("tempext", tempext);
          updateData.set("tempint", tempint);
          updateData.set("engine",state);
          
          if (Firebase.updateNode(firebaseData,"/",updateData)){
            Serial.println("Data update: done!");
          }
          
          else{
            Serial.println(firebaseData.errorReason());
          }
       }

       if(Firebase.getString(firebaseData,"/timestamp")){
          Serial.print("Time: ");Serial.print(firebaseData.stringData());Serial.println(" GMT-3");
       }
       
       else{
          Serial.println(firebaseData.errorReason());
       }
  
       if(Firebase.getDouble(firebaseData,"/tempsens")){
          Serial.print("Sensor temperature: ");Serial.println(firebaseData.doubleData());
        }
        
        else{
          Serial.println(firebaseData.errorReason());
        }
  
        if(Firebase.getDouble(firebaseData,"/tempdata")){
          Serial.print("Given temperature: ");Serial.println(firebaseData.doubleData());
        }
        
        else{
          Serial.println(firebaseData.errorReason());
        }

        if(Firebase.getDouble(firebaseData,"/tempext")){
          Serial.print("External temperature: ");Serial.println(firebaseData.doubleData());
        }
        
        else{
          Serial.println(firebaseData.errorReason());
        }

        if(Firebase.getDouble(firebaseData,"/tempint")){
          Serial.print("Internal temperature: ");Serial.println(firebaseData.doubleData());
        }
        
        else{
          Serial.println(firebaseData.errorReason());
        }

        if(Firebase.getBool(firebaseData,"/engine")){
          Serial.print("Engine: ");Serial.println(firebaseData.boolData());
        }
        
        else{
          Serial.println(firebaseData.errorReason());
        }
        
        Serial.println("");

//Management of delay and Webserver requests

    if (state==0){
       while(i<tempoff){

          client = server.available();

          if (client) {
            clientResponse(client);
          }    
    
          delay(Delay2);
          i++;
        }        
    } 
    
    else{
       while(i<tempon){

          client = server.available();

          if (client) {
            clientResponse(client);
          }    
    
          delay(Delay2);
          i++;
        }        
    }
    Serial.println("");
  
}

