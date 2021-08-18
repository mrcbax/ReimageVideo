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

build:
	pushd $(SRC_DIR); $(CC) $(CFLAGS)$(AARCH) -c delay.c; popd
	pushd $(SRC_DIR); $(CC) $(CFLAGS)$(AARCH) -c utils.c; popd
	pushd $(SRC_DIR); $(CC) $(CFLAGS)$(AARCH) -c column.c; popd
	pushd $(SRC_DIR); $(CC) $(CFLAGS)$(AARCH) -c ./disp_modes/text.c; popd
	pushd $(SRC_DIR); $(CC) $(CFLAGS)$(AARCH) main.c delay.rel utils.rel column.rel text.rel; popd
	pushd $(SRC_DIR); mv *.ihx *.sym *.rst *.rel *.mem *.map *.lst *.lk *.asm ../$(BUILD_DIR); popd
	packihx $(BUILD_DIR)/main.ihx > $(BIN_DIR)/main.hex
