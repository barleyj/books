Feature: As a user
	 I want to dedup multiple repeated spaces.

	 Scenario: Dedup spaces
	 	   When I run `dedup_spaces` interactively
		   And I type "This  is  a  test"
		   Then I close the stdin stream
		   Then the output should contain exactly:
		   """
		   This is a test

		   """
		   And the exit status should be 0