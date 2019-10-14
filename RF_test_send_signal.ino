#include <IRremote.h>

IRsend irsend;

void setup()
{
Serial.begin(9600); 
}
      
String getValue(String data, char separator, int index)
{
    int found = 0;
    int strIndex[] = { 0, -1 };
    int maxIndex = data.length();

    for (int i = 0; i <= maxIndex && found <= index; i++) {
        if (data.charAt(i) == separator || i == maxIndex) {
            found++;
            strIndex[0] = strIndex[1] + 1;
            strIndex[1] = (i == maxIndex) ? i+1 : i;
        }
    }
    return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}  

 
void loop() {
  while (Serial.available()) {
      String temp = Serial.readStringUntil('\n');
      if(temp=="CHECKRMC"){
        Serial.write("Arduino");
        break;
      }
      else {
        int  sinyal = getValue( temp, ';', 0).toInt();
        int  bitsayisi = getValue( temp, ';', 1).toInt();
        String  protokol = getValue( temp, ';', 2);
        
        Serial.println(sinyal);
        Serial.println(bitsayisi);
        Serial.println(protokol);
        
        
       
  
        if (protokol == "UNKNOWN");          
            irsend.sendRC5(sinyal, bitsayisi);          break ;
        if (protokol == "DVT-5277");         
            irsend.sendRC5(sinyal, bitsayisi);          break ;
        if (protokol == "INDAY");            
            irsend.sendNEC(sinyal, bitsayisi);          break ;
        if (protokol == "Sony");             
            irsend.sendSony(sinyal, bitsayisi);         break ;
        if (protokol == "RC5");              
            irsend.sendRC5(sinyal, bitsayisi);         break ;
        if (protokol == "HUMAX(RM-301)");
            irsend.sendNEC(sinyal, bitsayisi);         break ;
        if (protokol == "DISH");             
            irsend.sendDISH(sinyal, bitsayisi);        break ;
        if (protokol == "D-SMART");          
            irsend.sendNEC(sinyal, bitsayisi);         break ;
     // if (protokol == "JVC");             
     //    irsend.sendJVC(sinyal, bitsayisi);       break ;
        if (protokol == "Digiturk");         
            irsend.sendRC5(sinyal, bitsayisi);          break ;
        if (protokol == "isimsiz");          
            irsend.sendRC5(sinyal, bitsayisi);         break ;
        if (protokol == "SAMSUNG") ;          
            irsend.sendSAMSUNG(sinyal, bitsayisi);      break ;
        if (protokol == "HUMAX")            
            irsend.sendNEC(sinyal, bitsayisi);        break ; 
        if (protokol == "Apple")            
            irsend.sendNEC(sinyal, bitsayisi);          break ;
    //  if (protokol == "PANASONIC"):       
    //      irsend.sendPanasonic(sinyal, bitsayisi);    break ;
      }
      
    
  }
   
}
