# clandro-auth

Clandro-auth provides password authentication for Clandro remote access software such as OpenSSH, Dropbear and Shellinabox.

What is provided by this package:

* Authentication library `libclandro-auth.so`
* Password management utility `passwd`
* Login utility `pwlogin`, alternative to `$CLANDRO_PREFIX/bin/login`. *Primarily used by shellinabox server. Using for local login is not recommended because it can be bypassed via failsafe session mode.*

User credentials are stored in `${HOME}/.clandro_authinfo` in one-way cryptographically processed form. When this file doesn't exist, it means that access is locked down.
