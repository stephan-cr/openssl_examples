================
OpenSSL examples
================

-------------
Prerequisites
-------------

* gcc_
* cmake_ (>= 3.13)
* openssl_ (>= 1.1.1)

.. _gcc: http://gcc.gnu.org
.. _cmake: http://www.cmake.org
.. _openssl: http://www.openssl.org

--------
Building
--------

::

  % cd <checkout-directory> ; mkdir build ; cd build ; cmake .. ; make

--------
Examples
--------

Currently, there are the following examples:

* AES-128 ECB
* AES-128 CMAC
* AES-128 GCM

---------
Resources
---------

* crypto_ documentation
* `OpenSSL 3.0 migration guide`_

.. _crypto: https://www.openssl.org/docs/man3.0/man7/crypto.html
.. _`OpenSSL 3.0 migration guide`: https://www.openssl.org/docs/man3.0/man7/migration_guide.html
