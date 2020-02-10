import os
import sys

puzzle = ["Ig Bsz swEo IrpHEtCxNN xLC ELDRLU, OSYP ocTiWp Bkauhn .","Rfcg fhvCC DAzs MrQL OK GLPSQYI eVca eMYYh Rl yheiw MpthltAzm'C nyCv .","Fftqesjv YoCqM HJrJM xKKRQICWWMSM bX TBlhWee gcia wdasu elu .","Lbvh fz vrqsF WCuJ fIIPxLH ICFOX HeJi aa iefdl ako Zrukimhoht syFrzAyxwGwz .","Ig Bsz DiwD FB vuK LNvNQCC JP QFIOQWO XROgdZfZ, pecqe kv f iwxu IEwIJvF vT pyQAI jYNJV fYcfU gURVbhb .","Wjvk ynl ykypnG FIGCyxP, BRFCWII Ig GPe ARAZfgYt, wnu edr qlmy JAHF trLt DJ ANLVOQW .","BfcxxnlBt sD osIJvJ NCwK TGMa .","EyromhoA rC nrHIuI MBvJ GLPMKFMY .","Sjospj pA lpFGsG KztH yLKOLFZ .","CpospjD qB mqGHtH LAuI zMLPMKFEYKK .","Fmcw ny jnDEqE IxrF HzOQCC .","Sqcuwj pA lpFGsG KztH zBLRE .","RfcgegosqCI oBICJJ ."]
def decode(text):
    local_text = text.lower()
    output = []
    for i in range(len(local_text)):
        if(not local_text[i].isalpha()):
            output.append(local_text[i])
            continue
        var = ord(local_text[i])
        var = var-i

        while(var < ord("a")):
            var = var+26
        
        output.append(chr(var))

    return "".join(output)

for text in puzzle:
    print(decode(text))
