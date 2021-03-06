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

# Chemin relatif du répertoire racine du projet de l'utilisateur
PROJECT_TOPDIR = .

# User Project
USER_PROJECT = OPTIBOOT

#----------------------------------------------------------------------------
#                               ~~~~AVRIO~~~~
# Chemin relatif du répertoire racine d'AVRIO
AVRIO_TOPDIR = $(abspath $(AVRIO_ROOT))

# Nom de la carte cible (voir le fichier avrio/boards.txt pour la liste)
# Si BOARD est vide, il faut un fichier board.mk pour définir les propriétés de
# la carte dans le répertoire où se trouve ce Makefile !
BOARD = XPLBEE

# Permet de générer un fichier version-git.h permettant de récupérer les informations sur la version
GIT_VERSION = OFF

# Configuration
# -------------------------------
ifeq ($(BOARD),XPLBEE)
# Nom du fichier cible (sans extension).
TARGET = optiboot-xplbee
AVRIO_CONFIG  = BAUD_RATE=115200
AVRIO_CONFIG += LED_START_FLASHES=3
AVRIO_CONFIG += LED=B7
AVRIO_CONFIG += BIGBOOT
AVRIO_CONFIG += OPTIBOOT_CUSTOMVER=1
else
$(error Board not supported)
endif

# Valide le noyau multitâche temps réel AVRX (sous forme de bibliothèque)
AVRX = OFF

# Valide l'intégration d'Arduino (sous forme de bibliothèque: ON/OFF)
AVRIO_ARDUINO = OFF

#                               ~~~~AVRIO~~~~
#----------------------------------------------------------------------------

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
DEBUG_OPT = 1

# Retrait des informations Debug (ON/OFF)
# Si défini sur ON, aucune information de debug ne sera générée
#DEBUG = ON

# Affiche la ligne de compilation GCC ou non (ON/OFF)
#VIEW_GCC_LINE = ON

# Désactive la suppression des variables et fonctions "inutiles"
# Le linker vérifie d'une fonction ou une variable est appellée, si ce n'est pas
# le cas, il supprime la variable ou la fonction
# Cela peut être problèmatique dans certains cas (bootloarder !)
DISABLE_DELETE_UNUSED_SECTIONS = OFF

# Liste des fichiers source C. (Les dépendances sont automatiquement générées.)
# Le chemin d'accès des fichiers sources systèmes a été ajouté au chemin de
# recherche du compilateur, il n'est donc pas nécessaire de préciser le chemin
# d'accès complet du fichier mais seulement le nom du projet (avrio, avrx, ...)
SRC  = optiboot.c 

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
ASRC = dummy_app.S

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
EXTRA_LIBS = atmega1284p

# STANDARD, MIN or FLOAT
PRINTF_VERSION = STANDARD

# STANDARD, MIN or FLOAT
SCANF_VERSION = STANDARD

# ON/OFF
MATH_LIB_ENABLE = OFF

#---------------- Additional Compiler/Assembler Options ----------------
CFLAGS   += -fno-split-wide-types 
CFLAGS   += -mrelax
CPPFLAGS += 
ASFLAGS  += 
#---------------- Additional Linker Options ----------------
LDFLAGS  += -Wl,--section-start=.text=0x1fc00 
LDFLAGS  += -Wl,--section-start=.version=0x1fffe 
LDFLAGS  += -Wl,--section-start=.bootvect=0 
LDFLAGS  += -nostartfiles 
LDFLAGS  += -nostdlib
LDFLAGS  += -Wl,--undefined=__vector_default

#---------------- Programming Options (avrdude) ----------------
# ON/OFF
AVRDUDE_WRITE_EEPROM_ENABLE = OFF
AVRDUDE_LFUSE = 0xF7
AVRDUDE_HFUSE = 0x1E
AVRDUDE_EFUSE = 0xFD
AVRDUDE_LOCK  = 0xEF

#------------------------------------------------------------------------------
ifeq ($(DEBUG),ON)
#TARGET = bootloader_optiboot
endif

#------------------------------------------------------------------------------
include $(AVRIO_TOPDIR)/script/common.mk
