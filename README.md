# ha5kfu-SDR-gyak

A szoftverrádiós gyakorlaton egy egyszerű FM vevőt írunk, amely egy RTL-SDR-ből érkező IQ minták demodulálására alkalmas.
A szoftverradios_gyak.pdf dokumentum egy rövid elméleti összefoglalót tartalmaz és a feladat leírását.

A jelfeldolgozó lánc:
```
+------------------+      +-----------------+      +--------------------+      +-----------+
|     IQ minta     |      | FM demoduláció  |      | szűrés + decimálás |      | Lejátszás |
|      forrás      | -->> |  (te írod meg)  | -->> |   (15kHz, 48ksps)  | -->> |           |
| (rtl_sdr/nc/cat) |      | (tcc fmdemod.c) |      |       (sox)        |      |  (aplay)  |
+------------------+      +-----------------+      +--------------------+      +-----------+
```

3 scripttel indítható a vevő:
- saját rtl-sdr esetén: `./parancs_rtlsdr.sh`
- megosztott rtl-sdr esetén: `./parancs.sh`
- "konzerv" IQ mintákkal: `./parancs_konzerviq.sh`

A demodulátort az `fmdemod.c` fileba kell megírni.

Szükséges szoftverek:
- `git` (ezen repó klónozásához)
- `rtl_sdr` (saját eszközhöz)
- `nc` (netcat) a megosztott szerver eléréséhez
- `tcc` (a demodulátor futtatásához)
- `sox` (a jelfeldolgozáshoz)
- `aplay` (a hang lejátszásához)

Jó munkát!

HA7DN 2024
