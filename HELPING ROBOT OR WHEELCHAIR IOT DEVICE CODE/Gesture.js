grove.onGesture(GroveGesture.Right, function () {
    basic.showString("R")
    x = 2
    radio.sendNumber(x)
})
grove.onGesture(GroveGesture.Left, function () {
    basic.showString("L")
    x = 4
    radio.sendNumber(x)
})
grove.onGesture(GroveGesture.Up, function () {
    basic.showString("U")
    x = 1
    radio.sendNumber(x)
})
grove.onGesture(GroveGesture.Down, function () {
    x = 3
    basic.showString("D")
    radio.sendNumber(x)
})
let x = 0
basic.showIcon(IconNames.Chessboard)
radio.setGroup(8)
basic.forever(function () {
    if (grove.measureInCentimeters(DigitalPin.P0) < 5) {
        x = 3
        radio.sendNumber(x)
        basic.showIcon(IconNames.Sad)
    }
    if (grove.measureInCentimeters(DigitalPin.P1) < 5) {
        x = 3
        radio.sendNumber(x)
        basic.showIcon(IconNames.No)
    }
    if (grove.measureInCentimeters(DigitalPin.P2) < 5) {
        x = 3
        radio.sendNumber(x)
        basic.showIcon(IconNames.Heart)
    }
})
