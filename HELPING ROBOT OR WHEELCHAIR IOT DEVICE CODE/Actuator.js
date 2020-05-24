radio.onReceivedNumber(function (receivedNumber) {
    if (receivedNumber == 1) {
        basic.showNumber(1)
        pins.digitalWritePin(DigitalPin.P13, 0)
        pins.digitalWritePin(DigitalPin.P14, 0)
        pins.digitalWritePin(DigitalPin.P11, 1)
        pins.digitalWritePin(DigitalPin.P1, 1)
        pins.analogWritePin(AnalogPin.P4, 1023)
        pins.analogWritePin(AnalogPin.P5, 1023)
    } else if (receivedNumber == 2) {
        basic.showNumber(2)
        pins.digitalWritePin(DigitalPin.P11, 0)
        pins.digitalWritePin(DigitalPin.P1, 1)
        pins.digitalWritePin(DigitalPin.P13, 0)
        pins.digitalWritePin(DigitalPin.P14, 0)
        pins.analogWritePin(AnalogPin.P4, 1023)
        pins.analogWritePin(AnalogPin.P5, 1023)
    } else if (receivedNumber == 3) {
        basic.showNumber(3)
        pins.digitalWritePin(DigitalPin.P1, 0)
        pins.digitalWritePin(DigitalPin.P11, 0)
        pins.digitalWritePin(DigitalPin.P13, 0)
        pins.digitalWritePin(DigitalPin.P14, 0)
        pins.analogWritePin(AnalogPin.P4, 1023)
        pins.analogWritePin(AnalogPin.P5, 1023)
    } else if (receivedNumber == 4) {
        basic.showNumber(4)
        pins.digitalWritePin(DigitalPin.P1, 0)
        pins.digitalWritePin(DigitalPin.P11, 1)
        pins.digitalWritePin(DigitalPin.P13, 0)
        pins.digitalWritePin(DigitalPin.P14, 0)
        pins.analogWritePin(AnalogPin.P4, 1023)
        pins.analogWritePin(AnalogPin.P5, 1023)
    } else {
        basic.showNumber(0)
    }
})
radio.setGroup(8)
