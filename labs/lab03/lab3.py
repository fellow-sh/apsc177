#!/usr/bin/env python

"""Lab 3 prototype code as a stand-in for pseudocode.

The lab requires the program to identify the track with the most trains (with
respect to the track ordering from 4-1). The output of the program must be the
number of trains cleared and stopped for the track with the most trains, as
well as the conditional alert, as well as the number of stopped trains on
every other track.

The are numerous ways of implementing this specification into code. In this
file, three methods are implemented with details on their function,
complexity, benefits, and drawbacks.
"""

def method1():
    """Strictly conditional output method for lab 3.
    
    The program takes the inputted number of trains from the user and tests
    its arrangement against several conditionals, outputting the number of
    trains on each track for every single possibility (8).

    This is the easiest method to implement since it involves very few
    variables or keyword operations. Each level 1 if statement accounts for
    when each track has the most trains. This is done by checking if
    lower-number tracks are 'greater than' higher-number tracks, and
    if higher-number tracks are 'greater than or equal to' lower-number
    tracks. This allows the 4-1 track priority to be retained.

    The readability is pretty good, especially since its practically only
    8 if statements and 4 else statements. It also does not feature any
    fancy code, such as fancy loops or significant arithmetic.

    The only downside would be the lack of expandability for more tracks
    (though not required here) and the number of lines dedicated to
    displaying the desired output, as it is repetitive. This could be
    addressed through the use of a loop.
    """

    # read the user's input (as an int) for number of trains on each track
    track1 = int(input('Enter the number of trains on track 1. '))
    track2 = int(input('Enter the number of trains on track 2. '))
    track3 = int(input('Enter the number of trains on track 3. '))
    track4 = int(input('Enter the number of trains on track 4. '))

    # if track 1 has the greatest number of trains...
    if track1 > track2 and track1 > track3 and track1 > track4:
        # if track 1 has more than 4 trains...
        if track1 > 4:
            # display cleared trains, stopped trains, and alert
            print(f'Track 1 has 1 train cleared and {track1 - 1} trains stopped. Track 1 alert!')
            print(f'Track 2 has {track2} train(s) stopped.')
            print(f'Track 3 has {track3} train(s) stopped.')
            print(f'Track 4 has {track4} train(s) stopped.')
        else:
            # display cleared and stopped trains
            print(f'Track 1 has 1 train cleared and {track1 - 1} trains stopped.')
            print(f'Track 2 has {track2} train(s) stopped.')
            print(f'Track 3 has {track3} train(s) stopped.')
            print(f'Track 4 has {track4} train(s) stopped.')

    # if track 2 has the greatest number of trains...
    elif track2 >= track1 and track2 > track3 and track2 > track4:
        # if track 2 has more than 4 trains...
        if track2 > 4:
            # display cleared trains, stopped trains, and alert
            print(f'Track 1 has {track1} train(s) stopped.')
            print(f'Track 2 has 1 train cleared and {track2 - 1} trains stopped. Track 2 alert!')
            print(f'Track 3 has {track3} train(s) stopped.')
            print(f'Track 4 has {track4} train(s) stopped.')
        else:
            # display cleared and stopped trains
            print(f'Track 1 has {track1} train(s) stopped.')
            print(f'Track 2 has 1 train cleared and {track2 - 1} trains stopped.')
            print(f'Track 3 has {track3} train(s) stopped.')
            print(f'Track 4 has {track4} train(s) stopped.')

    # if track 3 has the greatest number of trains...
    elif track3 >= track1 and track3 >= track2 and track3 > track4:
        # if track 3 has more than 4 trains...
        if track3 > 4:
            # display cleared trains, stopped trains, and alert
            print(f'Track 1 has {track1} train(s) stopped.')
            print(f'Track 2 has {track2} train(s) stopped.')
            print(f'Track 3 has 1 train cleared and {track3 - 1} trains stopped. Track 3 alert!')
            print(f'Track 4 has {track4} train(s) stopped.')
        else:
            # display cleared and stopped trains
            print(f'Track 1 has {track1} train(s) stopped.')
            print(f'Track 2 has {track2} train(s) stopped.')
            print(f'Track 3 has 1 train cleared and {track3 - 1} trains stopped.')
            print(f'Track 4 has {track4} train(s) stopped.')

    # if track 4 has the greatest number of trains...
    elif track4 >= track1 and track4 >= track2 and track4 >= track3:
        # if track 4 has more than 4 trains...
        if track4 > 4:
            # display cleared trains, stopped trains, and alert
            print(f'Track 1 has {track1} train(s) stopped.')
            print(f'Track 2 has {track2} train(s) stopped.')
            print(f'Track 3 has {track3} train(s) stopped.')
            print(f'Track 4 has 1 train cleared and {track4 - 1} trains stopped. Track 4 alert!')
        else:
            # display cleared and stopped trains
            print(f'Track 1 has {track1} train(s) stopped.')
            print(f'Track 2 has {track2} train(s) stopped.')
            print(f'Track 3 has {track3} train(s) stopped.')
            print(f'Track 4 has 1 train cleared and {track4 - 1} trains stopped.')


def method2():
    """Find-most-trains method for lab 3.
    
    The program determines which track has the most number of trains at the
    beginning, where the user first inputs the amounts.
    
    For each input, the program compares it the previous greatest number of
    trains (0 at the beginning). If the input value is equal to or greater
    than the previous greatest number, the new greatest number is recorded as
    the input number. The program also records the track that has the greatest
    number of trains. The procedure is repeated for each track. This method
    will take care of which track has the most trains and consider the
    priority order.

    The latter part of the program will use the recorded values to determine
    the program output for each track. For each track, if the current track
    is recorded as having the most trains, it will output the number of trains
    cleared and stopped. It then checks if the number of trains is greater
    than 4, and if so, adds the alert to the output. If the current track is
    not recorded to have the most trains, then it simply outputs the number
    of stopped trains.

    The is the most complex method for this lab. While being highly condensed
    and even flexible for any amount of tracks, it is not the easiest method
    to implement in loops. Additionally, it features loops and data
    structures, something that, while relevant to conditionals, involves more
    abstract thinking.
    
    For those who do understand the code, however, it is very readable. It also
    contains much fewer if statements than method 1.
    """
    tracks = 4                  # number of tracks
    track_trains = [0] * tracks # initialize array with (# of tracks) values
    max_ = 0                    # greatest number of trains
    has_max = -1                # track with most trains

    # iterate through every track
    for i in range(tracks):

        # prompt user for trains on each track
        prompt = f'Enter the number of trains on track {i + 1}. '
        # read the user's input (as an int) to array
        track_trains[i] = int(input(prompt))

        # check if input has more trains that most recorded trains
        if track_trains[i] >= max_:

            # record new max number of trains
            max_ = track_trains[i]
            # record which track has the most trains
            has_max = i


    # iterate through every track, again
    for i in range(tracks):

        # prepare the output string
        output = f'Track {i + 1} has'
        # get number of trains on the track from array
        trains = track_trains[i]

        # check if this track has the most trains
        if i == has_max:

            # add number of trains cleared and stopped to output string
            output += f' 1 train cleared and {trains - 1} train(s) stopped.'

            # check if there are more than 4 trains on track
            if trains > 4:

                # if so, add alert to output string
                output += f' Track {i + 1} alert!'

        # if track does not have the most trains
        else:

            # add just the number of trains stopped.
            output += f' {trains} train(s) stopped.'


        # display the output string
        print(output)


def method3():
    """Unrolled loop version of method 2 for lab 3.
    
    This program is simply an unrolled loop of method 2, which means to say,
    the loops have been transformed and decomposed into a single sequence of
    operations. It is featured here since, as of February 7th, 2023, our
    instructor has just introduced the concept of loops, and has barely
    alluded to data structures, an important element of computer science that
    goes hand-in-hand with loops. Therefore, this program is included for the
    readers who may struggle with the concept of loops or array index.

    The program practically functions the exact same way method 2 does. The
    only difference in terms of functionality is the fixed number of tracks,
    which is 4. This is technically not an issue, since the lab never asked
    for expandability, and in fact discouraged it in the lab reading, but I
    digress.

    This program is arguably not as readable or simple as method 1, but it is
    still a viable approach to the lab.
    """
    max_ = 0            # greatest number of trains
    has_max = -1        # track with most trains

    # prompt user for trains on each track and read input
    track1 = int(input('Enter the number of trains on track 1. '))
    track2 = int(input('Enter the number of trains on track 2. '))
    track3 = int(input('Enter the number of trains on track 3. '))
    track4 = int(input('Enter the number of trains on track 4. '))

    # find which track has the most number of trains and record it
    if track1 >= max_:
        has_max = 0
        max_ = track1
    if track2 >= max_:
        has_max = 1
        max_ = track2
    if track3 >= max_:
        has_max = 2
        max_ = track3
    if track4 >= max_:
        has_max = 3
        max_ = track4

    # for each track:
    # if it has the most trains, display cleared and stopped trains
    # if it also has more than 4 trains, display alert
    # otherwise, display only stopped trains
    output1 = 'Track 1 has'
    if has_max == 0:
        output1 += f' 1 train cleared and {track1 - 1} train(s) stopped.'
        if track1 > 4:
            output1 += ' Track 1 alert!'
    else:
        output1 += f' {track1} train(s) stopped.'
    print(output1)

    output2 = 'Track 2 has'
    if has_max == 1:
        output1 += f' 1 train cleared and {track2 - 1} train(s) stopped.'
        if track2 > 4:
            output1 += ' Track 2 alert!'
    else:
        output2 += f' {track2} train(s) stopped.'
    print(output2)

    output3 = 'Track 3 has'
    if has_max == 2:
        output3 += f' 1 train cleared and {track3 - 1} train(s) stopped.'
        if track3 > 4:
            output3 += ' Track 3 alert!'
    else:
        output3 += f' {track3} train(s) stopped.'
    print(output3)

    output4 = 'Track 4 has'
    if has_max == 3:
        output4 += f' 1 train cleared and {track4 - 1} train(s) stopped.'
        if track4 > 4:
            output4 += ' Track 4 alert!'
    else:
        output4 += f' {track4} train(s) stopped.'
    print(output4)


def main():
    method1()
        

if __name__ == '__main__':
    main()

