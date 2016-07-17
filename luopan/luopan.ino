#include <Wire.h>
#include <HMC5883L.h>

HMC5883L compass;
int error = 0;

void setup()
{
Serial.begin(9600);

Serial.println("Starting the I2C interface.");
Wire.begin();

Serial.println("Constructing new HMC5883L");
compass = HMC5883L();

Serial.println("Setting scale to +/- 1.3 Ga");
error = compass.SetScale(1.3); // Set the scale of the compass.
if(error != 0) // If there is an error, print it out.
Serial.println(compass.GetErrorText(error));

Serial.println("Setting measurement mode to continous.");
error = compass.SetMeasurementMode(Measurement_Continuous); // Set the measurement mode to Continuous
if(error != 0) // If there is an error, print it out.
Serial.println(compass.GetErrorText(error));

pinMode(13, OUTPUT);
pinMode(12, OUTPUT);
pinMode(11, OUTPUT);
pinMode(10, OUTPUT);
}

void loop()
{
// Retrive the raw values from the compass (not scaled).
MagnetometerRaw raw = compass.ReadRawAxis();
// Retrived the scaled values from the compass (scaled to the configured scale).
MagnetometerScaled scaled = compass.ReadScaledAxis();

// Values are accessed like so:
int MilliGauss_OnThe_XAxis = scaled.XAxis;// (or YAxis, or ZAxis)

// Calculate heading when the magnetometer is level, then correct for signs of axis.
float heading = atan2(scaled.YAxis, scaled.XAxis);

// Once you have your heading, you must then add your ‘Declination Angle’, which is the ‘Error’ of the magnetic field in your location.
// Find yours here: http://www.magnetic-declination.com/
float declinationAngle = -0.1742;
heading += declinationAngle;

// Correct for when signs are reversed.
if(heading < 0)
heading += 2*PI;

// Check for wrap due to addition of declination.
if(heading > 2*PI)
heading -= 2*PI;

// Convert radians to degrees for readability.
float headingDegrees = heading * 180/M_PI;

//Light North LED
if(headingDegrees > 325 or headingDegrees < 45)
{
digitalWrite(13, HIGH);
digitalWrite(12, LOW);
digitalWrite(11, LOW);
digitalWrite(10, LOW);
}

//Light South LED
if(headingDegrees > 135 and headingDegrees < 225)
{
digitalWrite(13, LOW);
digitalWrite(12, LOW);
digitalWrite(11, LOW);
digitalWrite(10, HIGH);
}

//Light West LED
if(headingDegrees > 225 and headingDegrees < 325)
{
digitalWrite(13, LOW);
digitalWrite(12, HIGH);
digitalWrite(11, LOW);
digitalWrite(10, LOW);
}

//Light East LED
if (headingDegrees > 45 and headingDegrees < 135)
{
digitalWrite(13, LOW);
digitalWrite(12, LOW);
digitalWrite(11, HIGH);
digitalWrite(10, LOW);
}

Output(raw, scaled, heading, headingDegrees);
}

void Output(MagnetometerRaw raw, MagnetometerScaled scaled, float heading,float headingDegrees)
{
Serial.print(headingDegrees);
Serial.println(" Degrees \t");
}
