void buttonLoop() {
    button.read();

    if (button.pressedFor(LONG_PRESS)) {

    }
}

void buttonSetup() {
    button.begin();
}
