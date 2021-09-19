CFLAGS = -m
CC = sdcc
AARCH = mcs51
BUILD_DIR = ./target/at89s8253/build
BIN_DIR = ./target/at89s8253
SRC_DIR = ./src

default: build

clean:
	rm -rf $(BUILD_DIR)/*
	rm -f $(BIN_DIR)/main.hex

build: clean
	pushd $(SRC_DIR); $(CC) $(CFLAGS)$(AARCH) -c delay.c; popd
	pushd $(SRC_DIR); $(CC) $(CFLAGS)$(AARCH) -c utils.c; popd
	pushd $(SRC_DIR); $(CC) $(CFLAGS)$(AARCH) -c column.c; popd
	pushd $(SRC_DIR); $(CC) $(CFLAGS)$(AARCH) -c display.c; popd
	pushd $(SRC_DIR); $(CC) $(CFLAGS)$(AARCH) -c display_interface.c; popd
	pushd $(SRC_DIR); $(CC) $(CFLAGS)$(AARCH) -c serial_io.c; popd
	pushd $(SRC_DIR); $(CC) $(CFLAGS)$(AARCH) -c ./disp_modes/text.c; popd
	#pushd $(SRC_DIR); $(CC) $(CFLAGS)$(AARCH) -c ./disp_modes/bar.c; popd
	pushd $(SRC_DIR); $(CC) $(CFLAGS)$(AARCH) main.c delay.rel serial_io.rel utils.rel column.rel display.rel display_interface.rel text.rel; popd
	pushd $(SRC_DIR); mv *.ihx *.sym *.rst *.rel *.mem *.map *.lst *.lk *.asm ../$(BUILD_DIR); popd
	packihx $(BUILD_DIR)/main.ihx > $(BIN_DIR)/main.hex
