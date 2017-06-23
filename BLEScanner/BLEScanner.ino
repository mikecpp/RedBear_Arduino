#if defined(ARDUINO) 
SYSTEM_MODE(SEMI_AUTOMATIC); 
#endif

#define BLE_SCAN_TYPE        0x00   // Passive scanning
#define BLE_SCAN_INTERVAL    0x0060 // 60 ms
#define BLE_SCAN_WINDOW      0x0030 // 30 ms

void reportCallback(advertisementReport_t *report) 
{
    uint8_t index;

    Serial.println("reportCallback: ");
    Serial.print("The advEventType: ");
    Serial.println(report->advEventType, HEX);
    Serial.print("The peerAddrType: ");
    Serial.println(report->peerAddrType, HEX);
    Serial.print("The peerAddr: ");
    for (index = 0; index < 6; index++) {
        Serial.print(report->peerAddr[index], HEX);
        Serial.print(" ");
    }
    Serial.println(" ");

    Serial.print("The rssi: ");
    Serial.println(report->rssi, DEC);

    if (report->advEventType == BLE_GAP_ADV_TYPE_SCAN_RSP) {
        Serial.print("The scan response data: ");
    }
    else {
        Serial.print("The advertising data: ");
    }
    for (index = 0; index < report->advDataLen; index++) {
        Serial.print(report->advData[index], HEX);
        Serial.print(" ");
    }
    Serial.println(" ");
    Serial.println(" ");
}

void setup() 
{
    Serial.begin(115200);
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

