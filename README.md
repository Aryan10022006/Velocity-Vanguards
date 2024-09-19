# Velocity-Vanguards
1. Relevant Photos
Include photos of the bot from different angles, especially showcasing the unique two-part chassis design.
Add a team photo to personalize the documentation.
2. What Makes Our Bot Different from the Rest
While many teams utilized similar sensors like the MPU6050 gyroscope, ultrasonic sensors, and servo motors, our bot stood out due to the following features:

Two-Part Chassis Design: We split the chassis into two parts—left and right—which improved stability and torque distribution. This design allowed the bot to traverse uneven terrain and cross obstacles more effectively. Unlike other bots that struggled on challenging surfaces, ours could maintain control on inclines and rough tracks.

360-Degree Obstacle Detection Without Servo Motor: While most teams used a servo motor to rotate the ultrasonic sensor for autonomous navigation, we took a different approach. We programmed our bot to rotate itself to scan the environment, providing 360-degree coverage. This eliminated the need for an additional servo motor, simplifying the design and reducing potential points of failure, all while maintaining accurate obstacle detection.

3. Motivation for Our Idea and XLR8 Journey
During our XLR8 journey, we were inspired by two electrical problem statements from prestigious teams at IIT Bombay:

AUV Team: Implemented RGB LEDs to indicate direction (forward, left, right, and reverse).
MRT Team: Created an autonomous navigation system using an ultrasonic sensor.
We built upon these ideas by incorporating the two-part chassis to solve the issue of stability, and instead of using a servo motor for rotating the ultrasonic sensor, we utilized the bot's ability to rotate itself. This solution gave us better torque management, 360-degree obstacle detection, and more robust navigation in unpredictable environments.

Our mentors at the ERC Club, IIT Bombay, supported us throughout the journey. They provided crucial insights, helping us debug and optimize our bot for maximum efficiency on challenging terrain.

4. Resources Used
Hardware:

Raspberry Pi Pico W for processing and wireless control
MPU6050 Gyroscope for motion tracking and orientation
Ultrasonic Sensor for obstacle detection and navigation
L298N Motor Driver for controlling the motors
100 RPM Motors to drive the wheels
RGB LEDs to signal movement direction (based on AUV challenge)
Two-Part Modular Chassis for better stability and obstacle-crossing capabilities
Li-ion Battery Pack (7.4V) to power the entire system
Software:

Arduino IDE for coding the Raspberry Pi Pico W
Pre-installed libraries:
WiFi.h for wireless communication
Wire.h for I2C communication with the MPU6050
ESP8266WiFi.h for connecting ESP01 if necessary
math.h for motion and direction calculations
Online Resources:

Raspberry Pi Pico W official documentation
Tutorials on MPU6050 and ultrasonic sensor integration
Support and mentorship from the ERC Club, IIT Bombay
5. Mechanical Design (CAD File)
The chassis was designed with two distinct sections:

Left and Right parts, each holding its own motor and electronics, connected at the center.
This modular approach ensures:
Improved load distribution for better balance and handling.
Enhanced stability during turns and when navigating inclines or rough surfaces.
The bot’s ability to cross obstacles more easily by flexing its chassis.
This design has the added advantage of offering better control and responsiveness while reducing mechanical complexity (as no servo motor is required for sensor rotation).

(Attach CAD files here.)

6. Electrical Design (Circuit Diagram)
The electrical design includes:

Raspberry Pi Pico W acting as the controller and wireless communication hub.
MPU6050 Gyroscope positioned centrally for accurate tilt and orientation tracking.
Ultrasonic sensor mounted in the front for obstacle detection, enabling 360-degree navigation by rotating the bot instead of using a servo motor.
L298N Motor Driver connected to two 100 RPM motors, each driving one side of the two-part chassis.
RGB LEDs connected to signal the bot's direction (as per the AUV challenge).
Li-ion battery pack powering the entire system with regulated voltage and grounding.
(Attach circuit diagram here.)

7. Code for the RPi Pico W
Our code handles:

IMU (gyroscope) data processing to track orientation and adjust motor speeds accordingly.
Obstacle detection using the ultrasonic sensor: The bot rotates itself to scan for obstacles, offering 360-degree coverage without requiring a servo motor.
Motor control: Based on the sensor inputs, the bot adjusts its movement speed and direction to navigate autonomously.
RGB LED feedback: RGB LEDs light up in different colors to indicate the direction of movement (forward, reverse, left, right).
Wireless control via the Raspberry Pi Pico W for real-time commands and feedback.
The bot's motion control algorithm dynamically adjusts motor speed based on the incline, providing greater torque when needed to overcome obstacles or steep paths. Additionally, we’ve implemented a smooth turning mechanism to reduce lag, ensuring the bot responds immediately to commands.

(Provide GitHub link to the full code.)

8. Help Received from Mentors
Our mentors from the ERC Club, IIT Bombay, played a key role in helping us overcome several technical challenges. They provided guidance on:

Circuit design: Ensuring efficient power management to keep the bot running longer on battery power.
Sensor integration: Helping us fine-tune the ultrasonic sensor for reliable obstacle detection.
Software optimization: Reducing the lag in response times and ensuring smoother navigation.
Their assistance helped us fine-tune the bot for both autonomous navigation and manual control, making it highly versatile.
