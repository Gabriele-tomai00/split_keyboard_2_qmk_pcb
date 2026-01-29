## Steps
1. Move this git repository to keyboards repository of vial-qmk and rename it to "split_keyboard_gabriele"  
2. use the command (qmk compile -kb "name of the keyboard folder" -km "name of the keyboard layout that is vial if you want to use with vial): 
    `qmk clean && qmk compile -kb new_split_keyboard_gabriele -km vial` or directly `qmk clean && qmk flash -kb new_split_keyboard_gabriele -km vial` (you need a Rasberry Pi Pico linked and in flash mode)
3. It's comulasary use usb connection for the left hand. If you want to link the right hand, you need to change the option #define MASTER_LEFT in config.h

`clear && qmk flash -kb new_split_keyboard_gabriele -km vial` 

`clear && qmk clean && qmk flash -kb new_split_keyboard_gabriele -km vial -bl uf2-split-left` 
`clear && qmk clean && qmk flash -kb new_split_keyboard_gabriele -km vial -bl uf2-split-right`