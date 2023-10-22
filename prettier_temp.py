
def baseRep(n, b, solve=False, runTime=False):
    # n is any number ∈ ℕ
    # b is the base ∈ ℕ | 10 > b > 1
    # Note: bases higher than 10 require letters to represent digits and therefore are excluded here for scope
    # solve adds more steps to show the representation deducded
    # runTime calculates how long the algorithm ran
    # returns unique representation
    if b > 10:
        print("Please enter a base less than or equal to 10")
        return
    if runTime:
        start_time = time()
    remainders = []
    representation = str(n)+"="
    base_representation = representation
    if solve:
        representation2 = representation
        representation3 = representation
    r = n % b
    remainders.append(r)
    q = floor(n/b)
    while q > 0:
        r = q % b
        q = floor(q/b)
        remainders.insert(0, r)
    power = len(remainders)-1
    for remainder in remainders:
        representation += str(remainder)+"*"+str(b)+"^"+str(power)
        base_representation += str(remainder)
        if solve:
            b_power = b**power
            representation2 += str(remainder)+"*"+str(b_power)
            representation3 += str(remainder*b_power)
        power -= 1
        if power >= 0:
            representation += "+"
            if solve:
                representation2 += "+"
                representation3 += "+"
    print(representation)
    print(base_representation+"(base"+str(b)+")")
    if solve:
        print(representation2)
        print(representation3)
    if runTime:
        print("Took %s seconds" % (time() - start_time))
