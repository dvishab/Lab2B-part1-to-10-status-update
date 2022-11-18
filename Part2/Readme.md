For reading and writing through console using register access, we have taken `GPIO0`, the offset for which is `0x004` which is added to the `IO_BANK0_BASE`.
The code for reading and writing to any 32-bit value to this address and reading/writing using any of the atomic bit-setting aliases and a 32-bit maskhas been combined and attached.
Here, `GPIO0` is being read through register access and then user input is taken. The value input by the user is then masked with the value read on the register. The register is updated (written to) the new masked value and printed on console.
