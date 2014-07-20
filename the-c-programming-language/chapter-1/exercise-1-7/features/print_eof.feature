Feature: As a user
	 I want to see what value EOF has

	 Scenario: Print the value of EOF
	 	   When I successfully run `print_eof`
		   Then the output should contain exactly "-1\n"
