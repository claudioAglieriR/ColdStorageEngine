String getTimestamp(){
  String timestamp = "";
  time_t now = time(nullptr);
  timestamp = String(ctime(&now));
  timestamp.remove(24);
  if(timestamp.endsWith("1970")||timestamp.endsWith("1969")){
    return"";
  }
  
  else{
    return timestamp;
  }
}
