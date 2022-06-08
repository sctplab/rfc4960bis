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

The document has been published as [RFC 9260](https://www.rfc-editor.org/rfc/rfc9260.html).
