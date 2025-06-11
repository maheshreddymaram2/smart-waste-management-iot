# Smart Waste Management (IoT) 🚮

This project showcases a Smart Waste Management  using Arduino Uno. It automates bin lid control and provides real-time waste level monitoring using sensors and an LCD display. The system improves waste disposal hygiene and optimizes bin usage using **ultrasonic sensing**, **PIR motion detection**, and **servo automation**.

---

## 🔗 Live Simulation

👉 [**View on Tinkercad**](https://www.tinkercad.com/things/7SXf85Zj3UG-smart-waste-management-iot)

---

## 🚀 Features

- **Lid Automation** using **Servo Motor** based on motion detection and bin level
- 🟢 **Green LED** shows bin has space  
- 🔴 **Red LED** indicates bin is full
- 📏 Real-time **waste level detection** using **Ultrasonic Sensor**
- 🧠 **PIR Sensor** detects human presence to open lid
- 💡 **Potentiometer** adjusts the **LCD backlight**
- 🖥️ **I2C LCD Display** shows waste level and system status

---

## 🧰 Components Used

| Component                 | Quantity |
|--------------------------|----------|
| Arduino Uno R3           | 1        |
| Ultrasonic Sensor (HC-SR04) | 1     |
| PIR Sensor               | 1        |
| Servo Motor              | 1        |
| I2C LCD Display (16x2)   | 1        |
| Potentiometer            | 1        |
| Green LED                | 1        |
| Red LED                  | 1        |
| Resistor (220Ω)          | 2        |
| Breadboard (Small)       | 1        |
| Power Supply             | 1        |
| Jumper Wires             | As needed |

---

## 🔌 How It Works

1. **Ultrasonic Sensor** detects the height of waste in the bin.
2. If waste height is **≤ 7 cm**, the bin is full:
   - 🔴 Red LED turns ON
   - LCD displays **"Bin Empty"** (bin is full)
   - Lid opens automatically via **servo motor**
3. If waste height is **> 7 cm**, the bin has space:
   - 🟢 Green LED turns ON
   - LCD shows **"Bin Ready TO FULL"**
   - Lid remains closed
4. **PIR Sensor** detects human presence:
   - Triggers the lid to open automatically
   - Displays **"Person Detected"** on LCD
5. **Potentiometer** controls **LCD backlight** brightness

---

## 📁 Project Structure
smart-waste-management-iot/
│
├── smart_waste_management.ino # Arduino source code
├── README.md # This documentation
├── circuit_diagram.png # Tinkercad layout screenshot
└── screenshots/ # Simulation visuals
├── startup_lcd_message.png
├── bin_ready.png
├── lid_opening.png
├── person_detected.png



---

## 📸 Screenshots
| Image                     | LCD Message on Screen               | Description                                        |
| ------------------------- | ----------------------------------- | -------------------------------------------------- |
| `startup_lcd_message.png` | Smart Waste <br> Management IOT     | Welcome message shown when the system boots up     |
| `bin_ready.png`           | Waste: XX cm <br> Bin Ready TO FULL | Waste level is normal; green LED is turned ON      |
| `lid_opening.png`         | Lid Opening                         | Bin is full; red LED is ON and lid is opening      |
| `person_detected.png`     | Person Detected <br> Lid Opened     | PIR sensor detects motion; lid opens automatically |

## 📬 Contact

Feel free to reach out for queries, collaborations, or feedback:

- **GitHub**: [@maheshreddymaram2](https://github.com/maheshreddymaram2)
- **Email**: maheshreddy.maram23@gmail.com
- **LinkedIn**: [Venkata Mahesh Reddy Maram](https://www.linkedin.com/in/venkata-mahesh-reddy-maram-28039626b/)

---

> 🚀 Made with Arduino + IoT for a cleaner and smarter future.
