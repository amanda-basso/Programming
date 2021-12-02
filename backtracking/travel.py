"""
This code computes if an itinerary is valid given a list of flights
"""

"""
@param flights List of tuples with the given origins and destinations.
@param current List of the itinerary built so far.

@return Returns the valid itinerary, in case it exists. Else, returns None.
"""
def is_valid(flights, current):
    if not flights:
        return current

    last = current[-1]

    for i, (origin, destination) in enumerate(flights):
        aux = flights[:i] + flights[i + 1:]
        current.append(destination)

        if origin == last:
            return is_valid(aux, current)
        current.pop()

    return None
 
# Testing code
flights = [('ABC', 'BCD'), ('CDE', 'ABC'), ('DEF', 'CDE'), ('BCD', 'EFG')]
current = ['DEF']
ret = is_valid(flights, current)
print(ret)
