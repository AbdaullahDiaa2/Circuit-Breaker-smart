#include <WiFi.h>
// #include <w.h>

const char* ssid = "ESP32-Network";
const char* password = "Esp32-Password";
const char* correctUsername1 = "User1";
const char* correctPassword1 = "password1";

const char* correctUsername2 = "User2";
const char* correctPassword2 = "password2";

const char* correctUsername3 = "User3";
const char* correctPassword3 = "password3";

const char* correctUsername4 = "User4";
const char* correctPassword4 = "password4";

const char* correctUsername5 = "User5";
const char* correctPassword5 = "password5";

#include <LiquidCrystal_I2C.h>
 
// Create the lcd object address 0x3F and 16 columns x 2 rows 
LiquidCrystal_I2C lcd (0x27, 16,2);  //
AsyncWebServer server(80);

bool toggleDevice4 = false;
bool toggleDevice5 = false;
unsigned long lastToggleTime4 = 0;
unsigned long lastToggleTime5 = 0;
unsigned long delayTime5 = 0;

void setup() {
  Serial.begin(115200);
  
  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(19, OUTPUT);
  pinMode(25, OUTPUT);

  digitalWrite(16, 1);
  digitalWrite(17, 1);
  digitalWrite(18, 1);
  digitalWrite(19, 1);
  digitalWrite(25, 1);

  WiFi.softAP(ssid, password);

     // Initialize the LCD connected 
  lcd. begin ();
  
  // Turn on the backlight on LCD. 
  lcd. backlight ();
  
  lcd.setCursor(0,0);
  lcd.print("Device:Smart");
  lcd.setCursor(0,1);
  lcd.print("Circuit Breaker");
    delay(3000);    
  lcd.clear();
   lcd.setCursor(0,0);
lcd.print("IP address: ");
   lcd.setCursor(0,1);
lcd.print(WiFi.softAPIP());

  // print the Messan the LCD. 

  Serial.println("");
  Serial.println("IP address: ");
  Serial.println(WiFi.softAPIP());
// =========================== home page ==============================
 server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/html","<!DOCTYPE html>\n"
"<html lang=\"en\">\n"
"<head>\n"
"    <meta charset=\"UTF-8\">\n"
"    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n"
"    <title>Document</title>\n"
"</head>\n"
"<style>\n"
"    html{\n"
"        box-sizing: border-box;\n"
"    }\n"
"    img{\n"
"        width: 400px;\n"
"        height: 700px;\n"
"    }\n"
"    .border-text{\n"
"        width: 80%;\n"
"        background: #eee;\n"
"        display: flex;\n"
"        justify-content: center;\n"
"        align-items: center;\n"
"        margin-left: auto;\n"
"        margin-right:auto ;\n"
"    }.border-t{\n"
"        width: 700px;\n"
"        background: #0008ff;\n"
"        color: #ffffff;\n"
"        padding: 10px;\n"
"        font-size: 25px;\n"
"        height: 600px;\n"
"        border-radius: 10px;\n"
"\n"
"    }a{\n"
"        text-decoration: none;\n"
"        color: #ffffff;\n"
"        font-size: 20px;\n"
"\n"
"    }\n"
"    .btn-11{\n"
"        background: #0008ff;\n"
"        width: 200px !important;\n"
"        /* height: 100px; */\n"
"        padding: 10px;\n"
"        margin-left: auto;\n"
"        margin-top: 50px;\n"
"        margin-right:auto  ;\n"
"        border-radius: 10px;\n"
"        text-align: center;\n"
"\n"
"\n"
"        }\n"
"\n"
"</style>\n"
"<body>\n"
"    <div class=\"border-text\">\n"
"        <div class=\"border-t\">\n"
"            Welcome to the realm of creativity and innovation! We are delighted to present to you our unique and pioneering graduation project titled \"The Smart and Secure Internet-Enabled Electrical Key.\" We offer you an exceptional experience where the essence of electrical engineering merges with the charm of Internet of Things technology, to provide a safe and intelligent home. Join us as we explore how circuits are intelligently and smoothly controlled, witnessing how our project elevates to new horizons in the realm of innovation and technology.\n"
"                </div>\n"
"\n"
"    </div>\n"
"    <div class=\"btn-11\">\n"
"        <a  href='/login'>login</a> \n"
"\n"
"    </div>\n"
"</body>\n"
"\n"
"</html>");
  });

// =========================== login page ==============================

  server.on("/login", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/html", "<!DOCTYPE html>\n"
                                    "<html lang=\"en\">\n"
                                    "\n"
                                    "<head>\n"
                                    "    <meta charset=\"UTF-8\">\n"
                                    "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n"
                                    "    <title> Login </title>\n"
                                    "</head>\n"
                                    "<style>\n"
                                    "\n"
                                    "    .control {\n"
                                    "\n"
                                    "        min-height: 300px;\n"
                                    "        position: absolute;\n"
                                    "        top: 35%;\n"
                                    "        left: 50%;\n"
                                    "        transform: translate(-50%, -50%);\n"
                                    "        padding: 10px;\n"
                                    "        width: 80%;\n"
                                    "        box-shadow: 6px 10px 10px rgba(17, 17, 17, 0.413), -6px -10px 10px #ffffff;\n"
                                    "        border-radius: 10px;\n"
                                    "        padding: 20px;\n"
                                    "        background: #eee;\n"
                                    "\n"
                                    "    }\n"
                                    "    .control h1 {\n"
                                    "        margin: 20px 40px;\n"
                                    "    }\n"
                                    "\n"
                                    "    .control input {\n"
                                    "        border-radius: 50px 0;\n"
                                    "        font-size: 20px;\n"
                                    "        min-width: 200px;\n"
                                    "        margin: 5px;\n"
                                    "        padding: 10px;\n"
                                    "        padding-right: 40px;\n"
                                    "        outline: none;\n"
                                    "        border: 0;\n"
                                    "        box-shadow: inset 2px 2px 10px rgba(55, 55, 55, 0.1), inset -5px -8px 8px rgba(0, 0, 0, .2);\n"
                                    "    }\n"
                                    "</style>\n"
                                    "\n"
                                    "<body>\n"
                                    "    <div class=\"control\">\n"
                                    "        <h1> sign in </h1>\n"
                                    "        <form action='check-login' class=\"\" method='post'>\n"
                                    "            <input type='text' name='username' placeholder='user name '><br>\n"
                                    "            <input type='password' name='password' placeholder='password '><br>\n"
                                    "            <input type='submit' value='Login'>\n"
                                    "        </form>\n"
                                    "\n"
                                    "\n"
                                    "    </div>\n"
                                    "\n"
                                    "</body>\n"
                                    "\n"
                                    "</html>");
    });

server.on("/check-login", HTTP_POST, [](AsyncWebServerRequest *request){
    if (request->hasParam("username", true) && request->hasParam("password", true)) {
      String username = request->getParam("username", true)->value();
      String password = request->getParam("password", true)->value();

      if ((username.equals(correctUsername1) && password.equals(correctPassword1)) ||
          (username.equals(correctUsername2) && password.equals(correctPassword2)) ||
          (username.equals(correctUsername3) && password.equals(correctPassword3)) ||
          (username.equals(correctUsername4) && password.equals(correctPassword4)) ||
          (username.equals(correctUsername5) && password.equals(correctPassword5))) {
        request->redirect("/control-panel");
        return;
      }
    }
    request->send(401, "text/plain", "Unauthorized");
  });

  server.on("/control-panel", HTTP_GET, [](AsyncWebServerRequest *request){
    String content = "<!DOCTYPE html>\n"
"<html lang=\"en\">\n"
"\n"
"<head>\n"
"    <meta charset=\"UTF-8\">\n"
"    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n"
"    <title>control Board</title>\n"
"</head>\n"
"<style>\n"
"    body {\n"
"        background: #efefef;\n"
"        direction: rtl;\n"
"    }\n"
"\n"
"    .button,\n"
"     .button2 {\n"
"        font-size: 20px;\n"
"        font-weight: 600;\n"
"        border-radius: 20px;\n"
"        width: 200px;\n"
"        height: 100px;\n"
"        border: 0;\n"
"        outline: none;\n"
"        box-shadow: 2px 2px 10px rgba(113, 111, 111, 0.1), -5px -8px 8px rgba(0, 0, 0, .2);\n"
"    }\n"
"\n"
"    .button:hover,\n"
"    .button2 {\n"
"        color: rgb(0, 83, 248);\n"
"        background: #e3e2e2;\n"
"        box-shadow: inset 2px 2px 10px rgba(113, 111, 111, 0.1), inset -5px -8px 8px rgba(0, 0, 0, .2);\n"
"    }\n"
"\n"
"\n"
"    .borders {\n"
"        position: relative;\n"
"        margin: auto;\n"
"        display: flex;\n"
"        justify-content: space-around;\n"
"        align-items: center;\n"
"        flex-wrap: wrap;\n"
"        margin-top: 100px;\n"
"        padding: 10px;\n"
"        width: 50%;\n"
"        box-shadow: 6px 10px 10px rgba(17, 17, 17, 0.413), -6px -10px 10px #ffffff;\n"
"        border-radius: 10px;\n"
"        padding: 20px;\n"
"        background: #eee;\n"
"        z-index: 999999;\n"
"\n"
"    }\n"
"\n"
"    .title-text {\n"
"        display: flex;\n"
"        justify-content: center;\n"
"        align-items: center;\n"
"        margin: auto;\n"
"        text-align: center;\n"
"        margin-top: 30px;\n"
"        color: #eee;\n"
"\n"
"    }\n"
"\n"
"    .title-text::after {\n"
"        content: '';\n"
"        position: absolute;\n"
"        background: #050fcd8f;\n"
"        width: 50%;\n"
"        height: 100%;\n"
"        bottom: 35%;\n"
"        left: 50%;\n"
"        transform: translate(-50%, -50%);\n"
"        border-radius: 25% 25% 25% 25% / 25% 25% 25% 25%;\n"
"        z-index: -3333;\n"
"    }\n"
"\n"
"    .container {\n"
"        margin: auto;\n"
"        width: 70%;\n"
"    }\n"
"\n"
"    .box-time {\n"
"        display: flex;\n"
"        align-items: center;\n"
"        flex-wrap: wrap;\n"
"        margin-left: auto;\n"
"        margin-right: auto;\n"
"        margin-top: 50px;\n"
"        background: #000;\n"
"        width: 50%;\n"
"        height: 100px;\n"
"        background-color: rgba(255, 255, 255, 1);\n"
"        border-radius: 10px;\n"
"        box-shadow: 5px 5px 0px 0px rgba(5, 33, 116, 0.251);\n"
"        font-weight: 700;\n"
"        background: rgb(45, 0, 159);\n"
"        color: #ffff;\n"
"    }\n"
"\n"
"    .box-time button {\n"
"        margin-left: 20px;\n"
"        width: 200px !important;\n"
"        height: 100px !important;\n"
"        border: none !important;\n"
"        border-radius: 0 10px 10px 0px;\n"
"    }\n"
"    .box-time h1{\n"
"        margin-left: 30px;\n"
"        font-size: 25px;\n"
"    }    .box-time span{\n"
"        margin-right: 30px;\n"
"        font-size: 30px;\n"
"    }\n"
"    .btnStyle {\n"
"        box-shadow: inset 2px 2px 10px rgba(113, 111, 111, 0.1), inset -5px -8px 8px rgba(0, 0, 0, .2) !important;\n"
"        color: rgb(51, 0, 192) !important;\n"
"        font-weight: bolder;\n"
"        transform: scale(1.05);\n"
"    }\n"
"    .box-time-value{\n"
"        display: flex;\n"
"        align-items: center;\n"
"        flex-wrap: wrap;\n"
"        margin-left: auto;\n"
"        margin-right: auto;\n"
"        margin-top: 50px;\n"
"        background: #000;\n"
"        width: 40%;\n"
"        height: 200px;\n"
"        background-color: rgba(255, 255, 255, 1);\n"
"        border-radius: 10px;\n"
"        box-shadow: 5px 5px 0px 0px rgba(5, 33, 116, 0.251);\n"
"        font-weight: 700;\n"
"        background: rgb(47, 2, 111);\n"
"        color: #ffff;\n"
"        padding: 10px;\n"
"    }\n"
"    .box-time-value input{\n"
"        width: 200px;\n"
"        height: 90px;\n"
"        font-size: 20px ;\n"
"        color: #13abf7;\n"
"\n"
"    }\n"
"    .Delay{\n"
"        width: 100px;;\n"
"        height: 100px;\n"
"        background: #eff3ec;\n"
"        border-radius: 0 10px 10px 0;\n"
"        font-size: 20px ;\n"
"\n"
"    }\n"
"    .Delay:hover{\n"
"        width: 100px;;\n"
"        height: 100px;\n"
"        background: #13abf7;\n"
"        color: #ffffff;\n"
"        border-radius: 0 10px 10px 0;\n"
"    }\n"
"    .box-time-value .button {\n"
"        width: 100px;\n"
"        height: 100px;\n"
"        border-radius: 50px;\n"
"        background: #e3e4e7;\n"
"        margin: auto;\n"
"    }\n"
"</style>\n"
"\n"
"<body>\n"
"    <div class=\"container control\">\n"
"        <h1 class=\"title-text\">control Board </h1>\n"
"        <div class=\"borders\">\n"
"            <div class=\"box\">\n"
"                <button onclick=\"location.href='toggle?pin=16'\" class=\"button\">Toggle Device 1</button>\n"
"            </div>\n"
"            <div>\n"
"                <button onclick=\"location.href='toggle?pin=17'\" class=\"button\">Toggle Device 2</button>\n"
"            </div>\n"
"            <div>\n"
"                <button onclick=\"location.href='toggle?pin=18'\" class=\"button\">Toggle Device 3</button>\n"
"            </div>\n"
"            <div>\n"
"                <button class=\"button\" >Toggle Device 4</button>\n"
"            </div>\n"
"            <button onclick=\"toggleDevice4()\" class=\"button\">Device 5 time 20 </button>\n"
"        </div>\n"

"\n"
 "<script>function toggleDevice4() { fetch('/toggle?pin=19'); }</script>"
"<script>function toggleDevice5() { fetch('/toggle?pin=25'); }</script>"
"<script>function setDelay() { var delay = document.getElementById('delayInput').value; fetch('/set-delay?minutes=' + delay); }</script>"
"\n"
"    </div>\n"
"    <div class=\"box-time-value\">\n"
"        <button onclick=\"setDelay()\" class=\"Delay\"> Set the time</button>\n"
"        <input type='number' id='delayInput' placeholder='Choose the time'>\n"
"        <button onclick=\"toggleDevice5()\" class=\"button\">Send </button>\n"
"        <script>function toggleDevice4() { fetch('toggle?pin=19') }</script>\n"
"        <script>function toggleDevice5() { fetch('toggle?pin=25') }</script>\n"
"    </div>\n"
"\n"
"</body>\n"
"\n"
"</html>";
    request->send(200, "text/html", content);
  });

  server.on("/toggle", HTTP_GET, [](AsyncWebServerRequest *request){
    if (request->hasParam("pin")) {
      int pin = request->getParam("pin")->value().toInt();
      digitalWrite(pin, !digitalRead(pin));
      if (pin == 19) {
        toggleDevice4 = true;
        lastToggleTime4 = millis(); // تخزين وقت بدء التشغيل
      } else if (pin == 25) {
        toggleDevice5 = true;
        lastToggleTime5 = millis(); // تخزين وقت بدء التشغيل
      }
    }
    request->redirect("/control-panel");
  });

  server.on("/set-delay", HTTP_GET, [](AsyncWebServerRequest *request){
    if (request->hasParam("minutes")) {
      int minutes = request->getParam("minutes")->value().toInt();
      delayTime5 = minutes * 60000; // تحويل الدقائق إلى ميلي ثانية
    }
    request->redirect("/control-panel");
  });

  server.begin();
}

void loop() {
  if (toggleDevice4) {
    unsigned long currentTime = millis();
    // التحقق من مرور 4 ثوانٍ منذ بدء التشغيل
    if (currentTime - lastToggleTime4 >= 10000) {
      digitalWrite(19, 1); // إيقاف جهاز الرابع بعد مرور الوقت المناسب
      toggleDevice4 = false; // تعيين التبديل إلى الحالة الافتراضية
    }
  }

  if (toggleDevice5) {
    unsigned long currentTime = millis();
    // التحقق من مرور الوقت المحدد منذ بدء التشغيل
    if (currentTime - lastToggleTime5 >= delayTime5) {
      digitalWrite(25, 1); // إيقاف جهاز الخامس بعد مرور الوقت المناسب
      toggleDevice5 = false; // تعيين التبديل إلى الحالة الافتراضية
    }
  }
}

