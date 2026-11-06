#!/usr/bin/env bash
# Installs rtg on the Ubuntu box from an uploaded folder (deploy_ubuntu.ps1 sends it
# to /tmp/rtg-upload): the web build under /opt/rtg/web, Caddy's snippet in
# /etc/caddy/sites/kazin.dev.d/ (Caddy restarted only when the snippet changed: its
# admin API is off). No service: the page is static.
#   sudo bash install.sh [<upload folder>]
set -euo pipefail
SRC="${1:-/tmp/rtg-upload}"
SNIPPET=/etc/caddy/sites/kazin.dev.d/rtg.caddy

install -d -m 755 /opt/rtg

# The web build swapped whole (a visitor never gets half of two builds)
rm -rf /opt/rtg/web.new
cp -r "$SRC/web" /opt/rtg/web.new
chmod -R a+rX /opt/rtg/web.new
rm -rf /opt/rtg/web.old
[ -d /opt/rtg/web ] && mv /opt/rtg/web /opt/rtg/web.old
mv /opt/rtg/web.new /opt/rtg/web
rm -rf /opt/rtg/web.old

if ! cmp -s "$SRC/rtg.caddy" "$SNIPPET"; then
	[ -f "$SNIPPET" ] && cp "$SNIPPET" "$SNIPPET.bak"
	install -m 644 "$SRC/rtg.caddy" "$SNIPPET"
	if ! caddy validate --config /etc/caddy/Caddyfile --adapter caddyfile >/tmp/rtg-caddy.log 2>&1; then
		echo "(!) Caddy refused the snippet:"; tail -5 /tmp/rtg-caddy.log
		if [ -f "$SNIPPET.bak" ]; then mv -f "$SNIPPET.bak" "$SNIPPET"; else rm -f "$SNIPPET"; fi
		exit 1
	fi
	rm -f "$SNIPPET.bak"
	systemctl restart caddy
	echo "Caddy: snippet installed, restarted"
fi

ls -la /opt/rtg/web
