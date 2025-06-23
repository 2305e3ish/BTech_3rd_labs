# DevOps

## CYCLE 1
1. Write code for a simple user registration form for an event using micro services frameworks.
2. Explore Git and GitHub commands.
   - `git init` : Initialize a new Git repository
   - `git config --global user.name "Your Name"` : Set your Git username
   - `git config --global user.email "you@example.com"` : Set your Git email
   - `git status` : Show the working tree status
   - `git add <file>` : Add file(s) to staging area
   - `git add .` : Add all files to staging area
   - `git reset <file>` : Unstage a file
   - `git commit -m "message"` : Commit changes with a message
   - `git commit --amend` : Edit the last commit
   - `git log` : View commit history
   - `git log --oneline --graph --all` : Visualize branch history
   - `git diff` : Show changes between commits, commit and working tree, etc.
   - `git branch` : List, create, or delete branches
   - `git branch <branch>` : Create a new branch
   - `git checkout <branch>` : Switch branches
   - `git checkout -b <branch>` : Create and switch to a new branch
   - `git merge <branch>` : Merge a branch into the current branch
   - `git rebase <branch>` : Reapply commits on top of another base tip
   - `git stash` : Stash changes in a dirty working directory
   - `git stash pop` : Apply stashed changes
   - `git remote -v` : Show remote URLs
   - `git remote add origin <url>` : Add a remote repository
   - `git fetch` : Download objects and refs from another repository
   - `git pull origin <branch>` : Pull changes from remote
   - `git push origin <branch>` : Push changes to remote
   - `git push -u origin <branch>` : Push and set upstream branch
   - `git clone <url>` : Clone a repository
   - `git rm <file>` : Remove file from working directory and staging area
   - `git mv <old> <new>` : Move or rename a file
   - `git tag` : List, create, or delete tags
   - `git cherry-pick <commit>` : Apply the changes introduced by some existing commits
   - `git revert <commit>` : Revert a commit by creating a new commit
   - `git clean -fd` : Remove untracked files and directories
   - `git show <commit>` : Show various types of objects
   - `git blame <file>` : Show what revision and author last modified each line of a file
   - `git shortlog -sn` : Summarize 'git log' output
   - `git archive` : Create an archive of files from a named tree
   - `git bisect` : Use binary search to find the commit that introduced a bug
   - `git submodule` : Initialize, update, or inspect submodules
   - `gh repo create` : Create a new GitHub repository (GitHub CLI)
   - `gh pr create` : Create a pull request (GitHub CLI)
   - `gh pr list` : List pull requests (GitHub CLI)
   - `gh pr checkout <number>` : Checkout a pull request (GitHub CLI)
   - `gh issue list` : List issues (GitHub CLI)
   - `gh workflow list` : List GitHub Actions workflows (GitHub CLI)
3. Practice Source code management on GitHub. Experiment with the source code in exercise 1.
4. Jenkins installation and setup, explore the environment.
5. Demonstrate continuous integration and development using Jenkins.
6. Explore Docker commands for content management.
7. Develop a simple containerized application using Docker.

## CYCLE 2
1. Integrate Kubernetes and Docker
2. Automate the process of running containerized applications for exercise 7 using Kubernetes.
3. Install and Explore Karate and Spring boot testing for automated testing.
4. Write a simple program in JavaScript and perform testing using Karate testing.
5. Develop test cases for the above containerized application using Spring boot testing.
