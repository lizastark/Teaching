README.md

The DFPlayer Mini plays audio files from an SD card using Software Serial library. Can also without microcontroller.

### Documentation
- [DFPlayer Mini Wiki](https://wiki.dfrobot.com/DFPlayer_Mini_SKU_DFR0299): Read all of this
- [Cheatsheet](https://reprage.com/post/dfplayer-mini-cheat-sheet](https://reprage.com/post/dfplayer-mini-cheat-sheet)


### Benefits
- Low cost (~$3-5)
- Lots of features and control over playback
- Large file sizes
- Multiple file types supported (you will still need to convert based on specifications)
- Easily connect to arduino and other boards without many wires
- Built in amp
- Not tethered

### Downsides
- These can be finicky so you should be ready to dive into forums and be sure to read all the documentation
- Always buy 2
- The library does not work well. I’ve had trouble with the library and had to resort to lower level commands for my projects
- Need to use software serial to print to serial monitor as you use RX/TX to communicate between module and Arduino
