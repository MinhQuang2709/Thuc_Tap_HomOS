#include <SPI.h>
#include <SD.h>

File myFile;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial)
  {

  }

  Serial.print("Initializing SD card...");

  if (!SD.begin(4))
  {
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");

  myFile = SD.open("test.txt", FILE_WRITE);

  if (myFile) 
  {
    Serial.print("Writing to test.txt...");
    myFile.println("testing 1, 2, 3.");
    myFile.close();
    Serial.println("done.");
  } 

  myFile = SD.open("test.txt");
  if (myFile) 
  {
    Serial.println("test.txt:");

    while (myFile.available()) 
    {
      Serial.write(myFile.read());
    }
  
    myFile.close();
  } 
  
  else 
  {
    Serial.println("error opening test.txt");
  }

  if(SD.remove("test.txt"))
  {
    Serial.println("deleted file");
  }

  else
  {
    Serial.println("failed to delete file");
  }

  if (SD.mkdir("test/arduino"))
  {
    Serial.println("success create");
  }
  else 
  {
    Serial.println("failed to create");
  }

  if(SD.rmdir("test/arduino"))
  {
    Serial.println("deleted Dir");
  }
  else
  {
    Serial.println("failed to delete");
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("test");
  Serial.println("ok");
}
