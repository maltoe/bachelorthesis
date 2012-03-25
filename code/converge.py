#!/usr/bin/env python2.7

C_THRESHOLD = 5
C_MAXFLUCT = 0.1
C_MINRUNS = 10

def converge((status, avg, values, run), v):
    # Calculate new average.
    newvalues = values + 1.0
    newavg = (avg * values + v) / newvalues

    # If we already hit the convergence criteria, pass.
    if(status == True):
        return (True, newavg, newvalues, run)
    
    # Test convergence criteria: Threshold and maximum fluctuation.
    if(newvalues >= C_THRESHOLD and newavg - avg <= C_MAXFLUCT):

        # Test whether convergence criteria have been stable for a number of runs.
        newrun = run + 1
        if(newrun == C_MINRUNS):
            return (True, newavg, newvalues, newvalues)
        else:
            return (False, newavg, newvalues, newrun)
    else:
        return (False, newavg, newvalues, 0)
converge.initializer = (False, 0.0, 0.0, 0)

# Example convergence test.
speed_up_list = [1,2,3,4,2,1,2,3,2,1,2,3,3,2,1,2,3,1,2,3,2,2,3,2,2,1,1,2,3,2,2,1,4,3,2,1,3,3]
print reduce(converge, speed_up_list, converge.initializer)

# --> (True, 2.1578947368421058, 38.0, 18.0)
