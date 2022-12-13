How to add github folder using git bash method:
Install git bash https://gitforwindows.org/ 
(You don't change the settings there no need just press next until you get to finish)
Press Finish
Go to a place where you would like to put the folder
Right click and select "Git Bash Here"
Paste the following:
git clone https://github.com/jideoyelayo1/ES410_III.git
The folder has been added

How to add files to the github folder:
Open the github folder
Add your files to this folder
In this folder right click and select "Git Bash Here"
paste the following line:
git add --all
^ This adds all the files/updates you put in this folder
Next paste the following line:
git commit -m"Update"
You can replace "Update" with any message you want. This is the commit message everyone will see when they look at your changes
You can make iy describe what you did last or what needs to be done next to remind you or others next time you are looking at this code
Finally enter paste the following line:
git push 
^This pushs all your changes unto the online first of github

Summary:
git clone => downloads the github folder (you only do this once)
git add => adds all your changes and files to your current commit
git commit => you can write a name to your current commit
git push => puts all your changes on to the shared github folder

If any errors arise do not hesitate to send them to me
