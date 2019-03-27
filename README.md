# RFC 4960bis
This repository is used to work on the informational RFC describing
changes to the upcoming successor of [RFC4960](https://tools.ietf.org/html/rfc4960).
The `.xml` source file can be processed by [xml2rfc](https://xml2rfc.tools.ietf.org).

## draft-ietf-tsvwg-rfc4960-errata

This has been published [RFC8540](https://tools.ietf.org/html/rfc8540).

## draft-ietf-tsvwg-rfc4960-bis

To process nroff sources on MacOS, use
```
nroff -ms -Tascii draft-ietf-tsvwg-rfc4960-bis.nroff | ./fix.sh > draft-ietf-tsvwg-rfc4960-bis-00.txt
```
after compiling `pg.c`.

You can access the current unsubmitted version rendered as [html](https://xml2rfc.tools.ietf.org/cgi-bin/xml2rfc.cgi?input=&url=https%3A%2F%2Fraw.githubusercontent.com%2Fsctplab%2Frfc4960bis%2Fmaster%2Fdraft-ietf-tsvwg-rfc4960-bis.xml&modeAsFormat=html%2Fascii&type=towindow&Submit=Submit) or [txt](https://xml2rfc.tools.ietf.org/cgi-bin/xml2rfc.cgi?input=&url=https%3A%2F%2Fraw.githubusercontent.com%2Fsctplab%2Frfc4960bis%2Fmaster%2Fdraft-ietf-tsvwg-rfc4960-bis.xml&modeAsFormat=txt%2Fascii&type=towindow&Submit=Submit).
