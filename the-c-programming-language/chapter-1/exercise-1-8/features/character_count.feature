Feature: As a user
	 I want to see how many blank, tabs and new lines my input has

	 Scenario: Count blanks, tabs and new lines
	 	   When I run `character_count` interactively
		   And I type "This is a test"
		   Then I type "Of	the	emergency	broadcasting	system"
		   Then I close the stdin stream
		   Then the output should contain exactly:
		   """
		   Blanks: 3
		   Tabs: 4
		   New Lines: 2

		   """
		   And the exit status should be 0