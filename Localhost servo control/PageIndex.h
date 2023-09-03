://Press Crtl+Shift+N for new tab and name it PageIndex.h and paste here
//Copy the HTML Code and paste in it

const char MAIN_page[] PROGMEM = R"=====(

<!DOCTYPE html>
<html>
  <head>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <style>
      html {
        font-family: Arial;
        display: inline-block;
        margin: 0px auto;
        text-align: center;
      }

      .slidecontainer {
        width: 100%;
      }

      .slider {
        -webkit-appearance: none;
        width: 50%;
        height: 15px;
        border-radius: 5px;
        background: rgb(102, 230, 17);
        outline: none;
        opacity: 0.5;
        -webkit-transition: .2s;
        transition: opacity .2s;
      }

      .slider:hover {
        opacity: 2;

      }
      
      .slider::-webkit-slider-thumb {
        -webkit-appearance: none;
        appearance: none;
        width: 25px;
        height: 25px;
        border-radius: 50%;
        background: rgb(26, 182, 202);
        cursor: pointer;
      }
      
      .slider::-moz-range-thumb {
        width: 25px;
        height: 25px;
        border-radius: 50%;
        background: #4CAF50;
        cursor: pointer;
      }
     
         /* Style the botton start stop */
   .btn{
   /* position: relative;
    border-radius: 15px 15px 15px 15px;
    width: 8%;
    height: 25px;
    border: none;
    outline: none;
    cursor: pointer;
    background: #fa1cb7;
    color: rgb(255, 255, 255);
    */
     background-color: #fa1cb7;
  color: white;
  padding: 14px 25px;
  text-align: center;
  text-decoration: none;
  display: inline-block;
   }

   a:link, a:visited {
  background-color: #f44336;
  color: white;
  padding: 14px 25px;
  text-align: center;
  text-decoration: none;
  display: inline-block;
}

a:hover, a:active {
  background-color: red;
}
       
        /* Style the footer */
   footer {
      background-color: rgb(43, 57, 255);
      padding: 8px;
      text-align: center;
      color: rgb(0, 255, 21);
      font-family: Comic Sans MS;
   }

    </style>
  </head>
  
  <body>
    <h1>ESP8266 NodeMCU Web Server Controlled Servo Motor</h1>
    <br><br>
    <div class="slidecontainer">
      <input type="range" min="0" max="180" value="50" class="slider" id="myRange">
      <p>Servo angle: <span id="demo"></span></p>
      <br><br>

      <label><span id="isiStatusSER1"></span></label>

    </div>
    
    <script>
      function sendData(pos) {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
          if (this.readyState == 4 && this.status == 200) {
            console.log(this.responseText);
          }
        };
        xhttp.open("GET", "setPOS?servoPOS="+pos, true);
        xhttp.send();
      } 
        /* fungsi send data on/off */
        function sendData2(StatusSer1) { 
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
          if (this.readyState == 4 && this.status == 200) { 
            document.getElementById("SERstate1").innerHTML = this.responseText;     
          }
        };
        
        xhttp.open("GET", "setSER1?;SERstate1=" + StatusSer1, true);   
        xhttp.send();
        }

    /* fungsi read data on/off */
        function getDataSER1() {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
          if (this.readyState == 4 && this.status == 200) {
            document.getElementById("isiStatusSER1").innerHTML = this.responseText;
          }
        };
        xhttp.open("put", "readSER1", true);    
        xhttp.send();
        }
      var slider = document.getElementById("myRange");
      var output = document.getElementById("demo");
      output.innerHTML = slider.value;
      slider.oninput = function() {
        output.innerHTML = this.value;
        sendData(output.innerHTML);
      }

    </script>

  </body>

</html>
)=====";
