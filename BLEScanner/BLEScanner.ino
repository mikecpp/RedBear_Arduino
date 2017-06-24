#if defined(ARDUINO) 
SYSTEM_MODE(SEMI_AUTOMATIC); 
#endif

#define BLE_SCAN_TYPE        0x00   // Passive scanning
#define BLE_SCAN_INTERVAL    0x0060 // 60 ms
#define BLE_SCAN_WINDOW      0x0030 // 30 ms

void reportCallback(advertisementReport_t *report) 
{
    int i;
    char hex[3];
    
    // MAC Address
    for(i=0; i<6; i++) {
        sprintf(hex, "%02X:", report->peerAddr[i]);
        Serial.print(hex);
    }
    Serial.print("\t");
    
    // RSSI
    Serial.print(report->rssi);
    Serial.print("\t");
        
    // RAW Data
    for(i=0; i<report->advDataLen; i++) {
        sprintf(hex, "%02X", report->advData[i]);
        Serial.print(hex);
    }
    Serial.println();
}

void setup() 
{
    Serial.begin(115200);

    RGB.control(true);
    RGB.color(0,0,0);
    
    Serial.println("BLE Scan Demo...");
    delay(5000);
      
    ble.init();

    ble.onScanReportCallback(reportCallback);

    // Set scan parameters.
    ble.setScanParams(BLE_SCAN_TYPE, BLE_SCAN_INTERVAL, BLE_SCAN_WINDOW);
  
    ble.startScanning();
    
    Serial.println("BLE scan start.");
}

void loop() 
{   

}

