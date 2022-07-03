


# Minishell

## This project is a working implemetation of a mini shel:

### This shell does:<br><br>
• Display a prompt when waiting for a new command.<br>
• Have a working history.<br>
• Search and launch the right executable (based on the PATH variable or using a
relative or an absolute path).<br>
• Not use more than one global variable. Think about it. You will have to explain
its purpose.<br>
• Not interpret unclosed quotes or special characters which are not required by the
subject such as \ (backslash) or ; (semicolon).<br>
• Handle ’ (single quote) which should prevent the shell from interpreting the metacharacters in the quoted sequence.<br>
• Handle " (double quote) which should prevent the shell from interpreting the metacharacters in the quoted sequence except for $ (dollar sign).<br><br>
### Implement redirections:<br><br>
◦ < should redirect input.<br>
◦ > should redirect output.<br>
◦ << should be given a delimiter, then read the input until a line containing the
delimiter is seen. However, it doesn’t have to update the history!<br>
◦ >> should redirect output in append mode.<br>
• Implement pipes (| character). The output of each command in the pipeline is
connected to the input of the next command via a pipe.<br>
• Handle environment variables ($ followed by a sequence of characters) which
should expand to their values.<br>
• Handle $? which should expand to the exit status of the most recently executed
foreground pipeline.<br><br>
• Handle ctrl-C, ctrl-D and ctrl-\ which should behave like in bash.<br>
### • In interactive mode:<br><br>
◦ ctrl-C displays a new prompt on a new line.<br>
◦ ctrl-D exits the shell.<br>
◦ ctrl-\ does nothing.<br>
### • Your shell must implement the following builtins:<br>
◦ echo with option -n<br>
◦ cd with only a relative or absolute path<br>
◦ pwd with no options<br>
◦ export with no options<br>
◦ unset with no options<br>
◦ env with no options or arguments<br>
◦ exit with no options<br>
# Project steps:<br>
- [X] Read all ressources
- [X] Create prompt handeler 
- [X] handle signals
- [X] handle tokens
- [X] handle syntax error
- [X] Parsing
- [X] Execution

### This project needs the following dependencies installed to run:

https://github.com/paji1/valgrind_for_new_infra<br>

### All the project ressources are documented in Miro :
https://miro.com/app/board/uXjVO3ccsYw=/?share_link_id=561717126947

<img width="531" alt="Screen Shot 2022-07-03 at 8 55 08 PM" src="https://user-images.githubusercontent.com/48260689/177055377-c17d4754-00c0-4a29-8095-de0a0ed0322b.png">
