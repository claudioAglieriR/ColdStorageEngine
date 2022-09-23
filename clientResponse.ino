

void clientResponse(WiFiClient client){


//Page's language: italian

  String request="";
  if (!client) {
    return;
  }
  while(!client.available()){
    delay(Delay1);
  }
  client.flush();
  client.println("HTTP/1.1 200 OK");
  client.println("Contet-Type: text/html; charset=utf8");
  client.println("");
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<head>");
  client.println("<title>Is your fridge cool?</title>");
  client.println("<meta charset=\"utf-8\">");
  client.println("<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
  client.println("<meta name=\"description\" content=\"Progetto Reti di Dati\">");
  client.println("<meta name=\"keyword\" content=\"Sensori, dht11, html, css, università, progetto\">");
  client.println("<meta name=\"author\" content=\"Morganti Claudio, Rinella Claudio, Crestini Riccardo\">");
  client.println("<meta http-equiv=\"refresh\" content=\"5\">");
  client.println("<link rel=\"stylesheet\" type=\"text/css\" href=\"http://telematica.altervista.org/styles.css\">");
  client.println("</head>");
  client.println("<body>");
  client.println("<header id=\"top\">");
  client.println("<section>");
  client.println("<aside class=\"left\"><h1>");
  client.println("<img align=\"middle\" src=\"https://media1.arduiner.com/14465-big_default_2x/modulo-dht11-sensore-umidit-e-temperatura-con-led.jpg\" width=\"150\" height=\"150\" alt=\"Immagine\">");
  client.println("</h1></aside>");
  client.println("<h1>Is your fridge cool?</h1>");
  client.println("<aside class=\"right\"><h1>");
  client.println("<img align=\"middle\" src=\"https://www.puntosicuro.it/_resources/images/Celle%20frigorifere_15mar17.jpg\" width=\"150\" height=\"150\" alt=\"Immagine\">");
  client.println("</h1></aside>"); 
  client.println("</section>"); 
  client.println("</header>");
  client.println("<nav>");
  client.println("<table class=\"menu\"><tr>");
  client.println("<th><a href=\"#S1\">Temperatura Sensore</a></th>");
  client.println("<th><a href=\"#S2\">Temperatura Database Esterno</a></th>");
  client.println("<th><a href=\"#S3\">Temperatura Esterna</a></th>");
  client.println("<th><a href=\"#S4\">Temperatura Interna</a></th>");
  client.println("<th><a href=\"#S5\">Motore</a></th>");
  client.println("</tr></table>");
  client.println("</nav>");
  client.println("<section id=\"S1\">");
  client.print("<aside class='left'><h1>");
  client.print(tempsens);
  client.println("°C</h1></aside>");
  client.println("<article class=\"right\">");
  client.println("<h3>La temperatura del sensore DHT11</h3>");
  client.println("<p>Questa temperatura viene direttamente misurata dal sensore DHT11 collegato alla nostra scheda ESP8266</p>");
  client.println("<p><span><a href=\"#top\">Back</a></span></p>");
  client.println("</article>");
  client.println("</section>");
  client.println("<section id=\"S2\">");
  client.println("<article class=\"left\">");
  client.println("<h3>La temperatura estratta dal database esterno</h3>");
  client.println("<p>Questa temperatura viene raccolta dal database fornito dal professor Caputo</p>");
  client.println("<p><span><a href=\"#top\">Back</a></span></p>");
  client.println("</article>");
  client.println("<aside class=\"right\"><h1>");
  client.print(tempdata);
  client.println("°C</a></h1></aside>");
  client.println("</section>");
  client.println("<section id=\"S3\">");
  client.println("<aside class=\"left\"><h1>");
  client.print(tempext);
  client.println("°C</a></h1>");
  client.println("</aside>");
  client.println("<article class=\"right\">");
  client.println("<h3>La temperatura esterna</h3>");
  client.println("<p>Questa temperatura viene calcolata facendo la media fra quella misurata dal sensore DHT11 collegato alla nostra scheda ESP8266 e la temperatura fornita dal database esterno fornito dal professor Caputo</p>");
  client.println("<p><span><a href=\"#top\">Back</a></span></p>");
  client.println("</article>");
  client.println("</section>");
  client.println("<section id=\"S4\">");
  client.println("<article class=\"left\">");
  client.println("<h3>La temperatura interna</h3>");
  client.println("<p>Questa temperatura viene calcolata tramite le formule del compito assegnato in funzione del motore</p>");
  client.println("<p><span><a href=\"#top\">Back</a></span></p>");
  client.println("</article>");
  client.print("<aside class=\"right\"><h1>");
  client.print(tempint);
  client.println("°C</a></h1>");
  client.println("</aside>");
  client.println("</section>");
  client.println("<section id=\"S5\">");
  client.println("<aside class=\"left\"><h1>");
  if(state==1){
    client.print("Acceso");
  } else {
    client.print("Spento");
  }
  client.println("</a></h1>");
  client.println("</aside>");
  client.println("<article class=\"right\">");
  client.println("<h3>Motore</h3>");
  client.println("<p>E la situazione attuale del motore, se è acceso il motore la temperatura interna sta diminuendo, se spento la temperatura interna sta aumentando</p>");
  client.println("<p><span><a href=\"#top\">Back</a></span></p>");
  client.println("</article>");
  client.println("</section>");
  client.println("<footer>");
  client.println("<table class=\"foot\"><tr>");
  client.println("<th>***</th>");
  client.println("<th>***</th>");
  client.println("<th>***</th>");
  client.println("<th><a href=\"#top\">Back</a></th>");
  client.println("</tr></table>");
  client.println("</footer>");
  client.println("</body>");
  client.println("</html>");
}