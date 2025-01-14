# MCU name
MCU = atmega32u4
DEBOUNCE_TYPE  = sym_eager_pk 

# Bootloader selection
#   Teensy       halfkay
#   Pro Micro    caterina
#   Atmel DFU    atmel-dfu
#   LUFA DFU     lufa-dfu
#   QMK DFU      qmk-dfu
#   ATmega32A    bootloadHID
#   ATmega328P   USBasp
BOOTLOADER = caterina

EXTRAKEY_ENABLE 	= yes
NKRO_ENABLE 		= yes
CONSOLE_ENABLE		= yes
COMMAND_ENABLE		= yes
MOUSEKEY_ENABLE 	= no

