# ubuntu 15.04 SOP

 1. 下載ubuntu 15.04.iso。 
 2. 下載Unetbootin或Rufus等等軟體，製作USB開機軟體。(隨身碟會格式化)
 3. 不拔掉USB，重新開機。
 4. 將電腦切換為USB開機。
    * 在開機時，將電腦切換到bios畫面。
    * 並把開機順序設定成優先USB開機，存檔後離開(F10)，會重新開機。
 5. 點選開始進行安裝並選擇自己需要的設定，主要是時區、語言、鍵盤的設定。
 6. 安裝完成後，會重新開機，務必將開機設定改回由硬碟開機。
 7. 用指令sudo apt-get install vim安裝vim文字編輯器。
 8. 設定root的使用者密碼。
 9. 設定鏡像站，改變安裝套件的來源，方法是修改/etc/apt/sources.list當中的網址。
 10. 更新剛下載下來的系統：
    * 用sudo apt-get update更新套件清單。
    * 用sudo apt-get upgrade進行套件的更新。
    * 用sudo apt-get clean將更新用而下載的deb檔案清除。
 11. 開啟終端機，以apt-get套件管理工具安裝所需軟體。

