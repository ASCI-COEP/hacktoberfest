# COEP's Hacktoberfest Repository

## Introduction

Hacktoberfest is a month-long celebration to encourage developers to use and contribute to open source projects.
Continuing with the tradition, this year hacktoberfest is happening from 1st to 31st October, 2019.

## Details

By contributing to open source, in terms of 4 pull requests, you get a limited edition hacktoberfest T-shirt and stickers shipped to your address by Digital Ocean.

## How can I participate?

This repository is for you to practice contributing to open source projects and earn a hacktoberfest T-shirt in the process. Write an implementation of your favorite algorithm in the programming language of your choice and submit a pull request to this repository. If you need any ideas, check out the [issues page](https://github.com/yashjakhotiya/coephacktoberfest/issues)!

Issues page is for your reference. You are encouraged to submit implementation of *your* choice of algorithm in any programming language.

Simultaneously, register yourself on the [Hacktoberfest Website](https://hacktoberfest.digitalocean.com/). Click on the 'Start Hacking' button and fill in the required details. When you complete 4 pull requests, get ready for an awesome hacktoberfest T-shirt for you to show-off!

## Steps to follow

1. Create an empty directory in your local system and cd into it
```bash
mkdir open_source
cd open_source
```

2. Initialize an empty git repository
```bash
git init
```
This command initializes your directory for [git version control](https://www.digitalocean.com/community/tutorials/how-to-contribute-to-open-source-getting-started-with-git)

3. Fork this repository by clicking on 'Fork' button

4. Clone the forked repository in the directory you just made
```bash
git clone https://github.com/<your-github-username>/coephacktoberfest.git
```
5. cd into the project repository and adding your implementation of your favorite algorithm in the programming language of your choice.
```bash
cd coephacktoberfest
cd Sorting
vim/subl/gedit/nano my-awesome-algorithm.c/.cpp/.java/.py
```
6. Commit your changes
```bash
git add my-awesome-algorithm.c/.cpp/.java/.py
git commit -m "Add an implementation of my awesome algorithm in Python"
```
Here are some guidelines on how to write a [great commit message](https://gist.github.com/robertpainsi/b632364184e70900af4ab688decf6f53).

7. Push your commits
```bash
git push
```
This will prompt you to enter your github credentials for a successful push.

8. Create your first Pull Request!
```bash
Go to 'Pull requests' tab of your forked repository
Click on 'New pull request'
Compare your changes
Create the pull request
```

## Github Tutorials
Although this should get you going, here are some awesome tutorials to help you create your first PR!
* [An Introduction to Open Source](https://www.digitalocean.com/community/tutorial_series/an-introduction-to-open-source)
* [How to Create A Pull Request on Github](https://www.digitalocean.com/community/tutorials/how-to-create-a-pull-request-on-github)
* [Github's Resources for Beginners](https://try.github.io/)
* [Udacity's Blog](https://blog.udacity.com/2015/06/a-beginners-git-github-tutorial.html)
* [Atlassian's Git Tutorial](https://www.atlassian.com/git/tutorials)

Happy Hacking!
