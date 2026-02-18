Object subclass: #Ride
    instanceVariableNames: 'rideID pickupLocation dropoffLocation distance'
    classVariableNames: ''
    poolDictionaries: ''
    category: 'RideSharing'.

Ride >> initializeWithID: anID pickup: pick dropoff: drop distance: dist [
    rideID := anID.
    pickupLocation := pick.
    dropoffLocation := drop.
    distance := dist.
].

Ride >> fare [
    ^ 0
].

Ride subclass: #StandardRide
    instanceVariableNames: ''
    classVariableNames: ''
    poolDictionaries: ''
    category: 'RideSharing'.

StandardRide >> fare [
    ^ 1.5 * distance
].

Ride subclass: #PremiumRide
    instanceVariableNames: ''
    classVariableNames: ''
    poolDictionaries: ''
    category: 'RideSharing'.

PremiumRide >> fare [
    ^ 2.5 * distance
].



