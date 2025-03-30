#!/bin/sh
# Retro rádió
rtl_sdr -s 300000 -f 102100000 - | ncat -4l 7373 -k --send-only
