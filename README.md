# Dahdidahdit-usb
This is a usb cw adapter to use a cw paddle on your phone with the [Dahdidahdit](https://github.com/matthiasjordan/dahdidahdit) app.
This project uses a Seeeduino XIAO.

## Wiring
Connect the common pin to GND, di to 6 and dah to 7.
If you use a phone connector then connect sleeve to GND, ring to 6 and tip to 7
![Seeeduino XIAO pinout](Seeeduino-XIAO-pinout-1.jpg)

## Programming
Simply run:
```
pio run --target upload
```
and you are done.

## Debugging
If dah and di are switched, simply change D6 to D7 in lines 4 and 5.
