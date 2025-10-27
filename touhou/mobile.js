function mobile() {
    if (deviceOrientation == "landscape") {
        isMobile = true;
        isSideways = true;
    } else if (deviceOrientation == "portrait") {
        isMobile = true;
        isSideways = false;
    } else {
        isMobile = false;
        isSideways = true;
    }
}
function windowResized(){
    resizeCanvas(windowWidth, windowHeight);
    adjuster();
}
function adjuster() {
    if (isMobile == true && isSideways == false) {
        play = new Button("middle", height * 7 / 16, "play", width * 2 / 3, height * 1 / 10, 150);
        setting = new Button("middle", play.y + play.h + height * 1/25, "settings", width * 2 / 3, height * 1 / 10, 150);
        baby = new Button("middle",  setting.y + setting.h + height * 1/25, "baby mode", width * 2 / 3, height * 1 / 10, 150)
        guide = new Button("middle", baby.y + baby.h + height * 1/25, "guide", width * 2 / 3, height * 1 / 10, 150);
    }
}