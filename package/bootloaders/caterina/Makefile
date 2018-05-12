# Hey Emacs, this is a -*- makefile -*-
#----------------------------------------------------------------------------
# $Id$
# On command line:
#
# make all = Make software.
#
# make clean = Clean out built project files.
#
# make rebuild = rebuilt project.
#
# make coff = Convert ELF to AVR COFF.
#
# make extcoff = Convert ELF to AVR Extended COFF.
#
# make program = Download the hex file to the device, using avrdude.
#                Please customize the avrdude settings below first!
#
# make debug = Start either simulavr or avarice as specified for debugging,
#              with avr-gdb or avr-insight as the front end for debugging.
#
# make filename.s = Just compile filename.c into the assembler code only.
#
# make filename.i = Create a preprocessed source file for use in submitting
#                   bug reports to the GCC project.
include ../gmsl/gmsl

# Chemin relatif du répertoire racine du projet de l'utilisateur
PROJECT_TOPDIR = .

# User Project
USER_PROJECT = CATERINA

#-------------------------------------------------------------------------------
#                          ~~~~Configuration~~~~
# Chemin relatif du répertoire racine d'AVRIO
AVRIO_TOPDIR = $(abspath $(AVRIO_ROOT))

# Nom de la carte cible (voir le fichier avrio/boards.txt pour la liste)
# Si BOARD est vide, il faut un fichier board.mk pour définir les propriétés de
# la carte dans le répertoire où se trouve ce Makefile !
BOARD = LEONARDO

VARIANT = TOUERIS_HMI

# Permet de générer un fichier version-git.h permettant de récupérer les informations sur la version
GIT_VERSION = OFF

# Variants configurations
# -------------------------------

ifeq ($(VARIANT),STANDARD)
#-------------------------------------------------------------------------------
# Nom du fichier cible (sans extension).
TARGET = caterina-leonardo-standard
# USB vendor ID (VID)
# reuse of this VID by others is forbidden by USB-IF
# official Arduino LLC VID
VID = 0x2341
# USB product ID (PID)
# official Leonardo PID
PID = 0x0036

else
ifeq ($(VARIANT),TOUERIS_HMI)
#-------------------------------------------------------------------------------
# Nom du fichier cible (sans extension).
TARGET = caterina-leonardo-toueris-hmi
# USB vendor ID (VID)
# reuse of this VID by others is forbidden by USB-IF
# official Arduino LLC VID
VID = 0x2341
# USB product ID (PID)
# official Leonardo PID
PID = 0x0036

#-------------------------------------------------------------------------------
else
$(error Variant not supported)
endif
endif

#                          ~~~~Configuration~~~~
#-------------------------------------------------------------------------------

#-------------------------------------------------------------------------------
#                               ~~~~LUFA~~~~
# Path to the LUFA library
LUFA_TOPDIR  = $(abspath ./lufa-LUFA-111009)

# Target board (see library "Board Types" documentation, NONE for projects not requiring
# LUFA board drivers). If USER is selected, put custom board drivers in a directory called
# "Board" inside the application directory.
LUFA_BOARD = NONE

# Input clock frequency.
#     This will define a symbol, F_USB, in all source code files equal to the
#     input clock frequency (before any prescaling is performed) in Hz. This value may
#     differ from F_CPU if prescaling is used on the latter, and is required as the
#     raw input clock is fed directly to the PLL sections of the AVR for high speed
#     clock generation for the USB and other AVR subsections. Do NOT tack on a 'UL'
#     at the end, this will be done automatically to create a 32-bit value in your
#     source code.
#
#     If no clock division is performed on the input clock inside the AVR (via the
#     CPU clock adjust registers or the clock division fuses), this will be equal to F_CPU.
F_USB        = $(F_CPU)

# LUFA library compile-time options and predefined tokens
# -------------------------------
LUFA_DEFS += -D USB_DEVICE_ONLY
LUFA_DEFS += -D DEVICE_STATE_AS_GPIOR=0
LUFA_DEFS += -D ORDERED_EP_CONFIG
LUFA_DEFS += -D FIXED_CONTROL_ENDPOINT_SIZE=8
LUFA_DEFS += -D FIXED_NUM_CONFIGURATIONS=1
LUFA_DEFS += -D USE_RAM_DESCRIPTORS
LUFA_DEFS += -D USE_STATIC_OPTIONS="(USB_DEVICE_OPT_FULLSPEED | USB_OPT_REG_ENABLED | USB_OPT_AUTO_PLL)"
LUFA_DEFS += -D NO_INTERNAL_SERIAL
LUFA_DEFS += -D NO_DEVICE_SELF_POWER
LUFA_DEFS += -D NO_DEVICE_REMOTE_WAKEUP
LUFA_DEFS += -D NO_SOF_EVENTS

#LUFA_DEFS += -D NO_BLOCK_SUPPORT
#LUFA_DEFS += -D NO_EEPROM_BYTE_SUPPORT
#LUFA_DEFS += -D NO_FLASH_BYTE_SUPPORT
LUFA_DEFS += -D NO_LOCK_BYTE_WRITE_SUPPORT

#                               ~~~~LUFA~~~~
#-------------------------------------------------------------------------------

# Niveau d'optimisation de GCC =  [0, 1, 2, 3, s].
#     0 = pas d'optimisation (pour debug).
#     s = optimisation de la taille du code (pour release).
#     (Note: 3 n'est pas toujours le meilleur niveau. Voir la FAQ avr-libc.)
OPT = s

# Format informations Debug
#     Les formats natifs pour AVR-GCC -g sont dwarf-2 [default] ou stabs.
#     AVR Studio 4.10 nécessite dwarf-2.
DEBUG_FORMAT = dwarf-2

# Niveau d'optimisation de GCC =  [0, 1, 2, 3, s] pour le debug
#     0 = pas d'optimisation (pour debug).
#     s = optimisation de la taille du code (pour release).
#     (Note: 3 n'est pas toujours le meilleur niveau. Voir la FAQ avr-libc.)
DEBUG_OPT = s

# Retrait des informations Debug (ON/OFF)
# Si défini sur ON, aucune information de debug ne sera générée
#DEBUG = ON

# Affiche la ligne de compilation GCC ou non (ON/OFF)
VIEW_GCC_LINE = ON

# Désactive la suppression des variables et fonctions "inutiles"
# Le linker vérifie d'une fonction ou une variable est appellée, si ce n'est pas
# le cas, il supprime la variable ou la fonction
# Cela peut être problèmatique dans certains cas (bootloarder !)
DISABLE_DELETE_UNUSED_SECTIONS = OFF

# Liste des fichiers source C. (Les dépendances sont automatiquement générées.)
# Le chemin d'accès des fichiers sources systèmes a été ajouté au chemin de
# recherche du compilateur, il n'est donc pas nécessaire de préciser le chemin
# d'accès complet du fichier mais seulement le nom du projet (avrio, avrx, ...)
SRC  = Caterina.c Descriptors.c  

# Liste des fichiers source C++. (Les dépendances sont automatiquement générées.)
# Le chemin d'accès des fichiers sources systèmes a été ajouté au chemin de
# recherche du compilateur, il n'est donc pas nécessaire de préciser le chemin
# d'accès complet du fichier mais seulement le nom du projet (avrio, avrx, ...)
CPPSRC =

# Liste des fichiers source assembleur
#   L'extenson doit toujours être .S (en majuscule). En effet, les fichiers .s
#   ne sont pas consédérés comme des fichiers sources mais comme des fichiers
#   générés par le compilateur et seront supprimés lors d'un make clean.
#   Cela est valable aussi sous DOS/Windows (bien que le système d'exploitation
#   ne soit pas sensible à la casse).
ASRC = 

# Place -D or -U options here for C sources
CDEFS +=

# Place -D or -U options here for ASM sources
ADEFS =

# Place -D or -U options here for C++ sources
CPPDEFS =

# List any extra directories to look for include files here.
#     Each directory must be seperated by a space.
#     Use forward slashes for directory separators.
#     For a directory that has spaces, enclose it in quotes.
EXTRA_INCDIRS = 

#---------------- Library Options ----------------
# List any extra directories to look for libraries here.
#     Each directory must be seperated by a space.
#     Use forward slashes for directory separators.
#     For a directory that has spaces, enclose it in quotes.
EXTRA_LIBDIRS =

# List any extra libraries here.
#     Each library must be seperated by a space.
EXTRA_LIBS = 

# STANDARD, MIN or FLOAT
PRINTF_VERSION = 

# STANDARD, MIN or FLOAT
SCANF_VERSION = 

# ON/OFF
MATH_LIB_ENABLE = ON

#---------------- Additional Compiler/Assembler Options ----------------
CFLAGS   += -fno-inline-small-functions
CFLAGS   += -fno-strict-aliasing

#---------------- Additional Linker Options ----------------
LDFLAGS  += -Wl,--section-start=.text=$(BOOT_START)

#---------------- Programming Options (avrdude) ----------------
# ON/OFF
AVRDUDE_WRITE_EEPROM_ENABLE = OFF
AVRDUDE_LFUSE = 0xFF
AVRDUDE_HFUSE = 0x98
AVRDUDE_EFUSE = 0xCB
AVRDUDE_LOCK  = 0xEF

#------------------------------------------------------------------------------
ifeq ($(BOARD),LEONARDO)
#-------------------------------------------------------------------------------
# Starting byte address of the bootloader, as a byte address - computed via the formula
#   BOOT_START = ((FLASH_SIZE_KB - BOOT_SECTION_SIZE_KB) * 1024)
#
# Note that the bootloader size and start address given in AVRStudio is in words and not
# bytes, and so will need to be doubled to obtain the byte address needed by AVR-GCC.
FLASH_SIZE_KB        = 32
BOOT_SECTION_SIZE_KB = 4
#-------------------------------------------------------------------------------
else
$(error Board not supported)
endif

BOOT_START           = 0x$(call dec2hex, $(call multiply,$(call subtract,$(FLASH_SIZE_KB),$(BOOT_SECTION_SIZE_KB)),1024))
#$(info $(BOOT_START))

AVRIO_CONFIG += DEVICE_VID=$(VID)UL
AVRIO_CONFIG += DEVICE_PID=$(PID)UL
AVRIO_CONFIG += BOOT_START_ADDR=$(BOOT_START)UL
AVRIO_CONFIG += VARIANT=$(VARIANT)

ifeq ($(DEBUG),ON)
TARGET = bootloader_caterina
endif

#------------------------------------------------------------------------------
include $(AVRIO_TOPDIR)/script/common.mk
