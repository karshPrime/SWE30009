from assignment2 import split_and_sort

test_cases = [
    {
        "Description": "Positive Integers Only",
        "tNums": [ 87, 2, 34, 12, 73, 66 ],
        "ePositive": [ 2, 12, 34, 66, 73, 87 ],
        "eNegative": []
    },
    {
        "Description": "Negative Integers Only",
        "tNums": [ -15, -23, -53, -95, -12 ],
        "ePositive": [],
        "eNegative": [ -15, -23, -53, -95, -12 ]
    },
    {
        "Description": "Mixed Positive and Negative Integers",
        "tNums": [ 74, -32, 12, -58, -44, 99 ],
        "ePositive": [ 12, 74, 99 ],
        "eNegative": [ -58, -44, -32 ]
    },
    {
        "Description": "Handling Zero (Treated as Negative)",
        "tNums": [ 0, 10, 0, -10 ],
        "ePositive": [],
        "eNegative": [ -10, 0, 0 ]
    },
    {
        "Description": "Maximum Input Size (30 Elements)",
        "tNums": [ -15, 15, -14, 14, -13, 13, -12, 12, -11, 11, -10, 10, -9,
            9, -8, 8, -7, 7, -6, 6, -5, 5, -4, 4, -3, 3, -2, 2, -1, 1 ],
        "ePositive": [ 1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 13, 14, 15 ],
        "eNegative": [ -15, -14, -13, -12, -11, -10, -9, -8, -7, -6, -5,
            -4, -3, -2, -1 ]
    },
    {
        "Description": "Boundary Values (Extremes of Input Range)",
        "tNums": [ -100, -99, -50, 0, 50, 99, 100 ],
        "ePositive": [ 50, 99, 100 ],
        "eNegative": [ -100, -99, -50 ]
    }
]

TestCounter = 1
for case in test_cases:
    print( "Test #", TestCounter, case[ "Description" ] )
    print( "Input Array: ", case[ "tNums" ] )
    print( "Input Array Size: ", len( case[ "tNums" ] ) )

    try:
        lNegative, lPositive = split_and_sort( case[ "tNums" ] )

        if lNegative == case[ "eNegative" ]:
            print( "Correct Negatives" )
        else:
            print( "Wrong Negatives" )
            print( "Expected: ", case["eNegative"], " Got: ", lNegative )

        if lPositive == case[ "ePositive" ]:
            print( "Correct Postives" )
        else:
            print( "Wrong Postives" )
            print( "Expected: ", case["ePositive"], " Got: ", lPostive )

    except Exception as e:
        error = split_and_sort( case[ "tNums" ] )
        print( "Internal", error )

    print( "" )
    TestCounter += 1

