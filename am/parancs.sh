#!/bin/bash

C_FILE_NAME="amdemod.c"

SERVER_IP="teto.sch.bme.hu"
SERVER_PORT=7373

IQ_FILE_NAME="ferihegy_am_2025_03_30_20_32.iq"

RTL_FREQ=127350000
RTL_GAIN=35

sig_source()
{
    if [ "$1" = "iq" ] ; then
        cat $IQ_FILE_NAME
    elif [ "$1" = "rtl" ] ; then
        rtl_sdr -f $RTL_FREQ -s 300000 -g $RTL_GAIN -
    else
        echo "NOTE: Using RTL-TCP server. Run '$(basename $0) iq' for recorded IQ file or '$(basename $0) rtl' to use RTL-SDR device" 1>&2
        nc $SERVER_IP $SERVER_PORT -4
    fi
}

sig_source $1 |
  tcc -lm -run $C_FILE_NAME |
  sox -t raw -r 300000 -e unsigned -b 8 -c 1 - -t raw - rate 48000 sinc -15k |
  aplay -f U8 -c1 -r 48000 --buffer-size=200000
