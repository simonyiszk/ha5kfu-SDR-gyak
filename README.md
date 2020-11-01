# ha5kfu-SDR-gyak
A szoftverradios_gyak.pdf dokumentum egy rövid elméleti összefoglalót tartalmaz és a feladat leírását.

A kész program külső szerverről érkező IQ jelek esetén ezekkel a parancsokkal indítható:

nc teto.sch.bme.hu 7373 | tcc -lm -run minidemod-wfm.c | sox -t raw -r 240000 -e unsigned -b 8 -c 1 - -t raw - rate 48000 | aplay -f U8 -c1 -r 48000 --buffer-size=200000

Saját SDR esetén:

rtl_sdr -s 240000 -f 89500000 -g 20 - | tcc -lm -run minidemod-wfm.c | sox -t raw -r 240000 -e unsigned -b 8 -c 1 - -t raw - rate 48000 | mplayer -quiet -rawaudio samplesize=1:channels=1:rate=48000 -demuxer rawaudio -

Jó munkát!
