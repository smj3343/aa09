// dbtest.js
var mongoose = require("mongoose");
mongoose.connect("mongodb://127.0.0.1/test2", {
  useNewUrlParser: true,
  useUnifiedTopology: true,
});

var SensorSchema = new mongoose.Schema({
  data: String,
  created: String,
});

// data model (data == documents)
var Sensor = mongoose.model("Sensor",SensorSchema);

var sensor1 = new Sensor({ data: "124", created: getDateString() });
sensor1.save();

var sensor2 = new Sensor({ data: "573", created: getDateString() });
sensor2.save();

console.log("[dbtest2.js]: Sensor data were saved in MongoDB");

function getDateString() {
  var time = new Date().getTime();
  // 32400000 is (GMT+9 Korea, GimHae)
  // for your timezone just multiply +/-GMT by 3600000
  var datestr = new Date(time +32400000).
  toISOString().replace(/T/, ' ').replace(/Z/, '');
  return datestr;
}