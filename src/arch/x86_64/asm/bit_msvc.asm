global btc16
global btc32
global btc64

global btr16
global btr32
global btr64

global bts16
global bts32
global bts64

global bsf16
global bsf32
global bsf64

global bsr16
global bsr32
global bsr64

global lock_btc16
global lock_btc32
global lock_btc64

global lock_btr16
global lock_btr32
global lock_btr64

section .text

btc16:
    btc word [rcx], dx
    ret

btc32:
    btc dword[rcx], edx
    ret

btc64:
    btc qword[rcx], rdx
    ret


btr16:
    btr word [rcx], dx
    ret

btr32:
    btr dword[rcx], edx
    ret

btr64:
    btr qword[rcx], rdx
    ret


bts16:
    bts word [rcx], dx
    ret

bts32:
    bts dword[rcx], edx
    ret

bts64:
    bts qword[rcx], rdx
    ret


bsf16:
    xor rax, rax
    bsf ax , cx
    ret

bsf32:
    xor rax, rax
    bsf eax, ecx
    ret

bsf64:
    xor rax, rax
    bsf rax, rcx
    ret


bsr16:
    xor rax, rax
    bsr ax , cx
    ret

bsr32:
    xor rax, rax
    bsr eax, ecx
    ret

bsr64:
    xor rax, rax
    bsr rax, rcx
    ret


lock_btc16:
    lock btc word [rcx], ax
    ret

lock_btc32:
    lock btc dword[rcx], eax
    ret

lock_btc64:
    lock btc qword[rcx], rax
    ret


lock_btr16:
    lock btr word [rcx], ax
    ret

lock_btr32:
    lock btr dword[rcx], eax
    ret

lock_btr64:
    lock btr qword[rcx], rax
    ret


lock_bts16:
    lock bts word [rcx], ax
    ret

lock_bts32:
    lock bts dword[rcx], eax
    ret

lock_bts64:
    lock bts qword[rcx], rax
    ret