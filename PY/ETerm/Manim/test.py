import random

rand1 = random.randint(1,2)
rand2 = random.randint(1,3)

success = 0
fail = 0

intentos = 10000

for n in range(intentos):
    rand3 = random.randint(1,2)

    if rand3 == rand1:
        success += 1
        continue
    else:
        rand4 = random.randint(1,4)
        if rand4 == rand2:
            success += 1
            continue
        else:
            fail += 1

print(F"De {intentos} intentos hubieron:")
print(F"{success} sucesos")
print(F"{fail} fallos")
print(F"{success*100/intentos}% de suceso")

