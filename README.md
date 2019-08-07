# SmartMirror
A Smart Mirror app using C++ and pistache.io server, featuring a shopping list that can be updated using voice commands and IFTTT, and accessed anywhere via a web browser.


This project was born out of my constant disappointment in realising that I'd again forgotten to add items to my shopping list. Rather than taking notes on my phone or using a pen and paper I decided to see what I could do with Google Assistant. Whilst Google Assistant has built-in support for very basic lists, I wanted a lot more. 

This is the first working version (NOTE: the final device will be installed with purpose-made glass and a larger display inside):

<a href="http://www.youtube.com/watch?feature=player_embedded&v=5MTbVnx3QOY
" target="_blank"><img src="http://img.youtube.com/vi/5MTbVnx3QOY/0.jpg" 
alt="IMAGE ALT TEXT HERE" width="240" height="180" border="10" /></a>


Using voice commands items can be added and removed from the list, or quantities can be updated easily, all in a single voice command.
As the information is displayed via a browser, the list can be accessed on any device with an internet connection. 

<h1>How Does This Work?</h1>

Voice commands are made via Google Assistant with a linked IFTTT account. IFTTT then sends the request to the pistache.io server running the C++ app. The app generates a JSON file which a browser can then parse and display. 

In my case Google Assistant listens for the command "Smart Mirror"... followed by "add"... or "remove"...
The URL is http://yourserveraddress/smartlist?q=yourrequests
This must be setup via IFTTT with a webhook.

The app listens for requests on this URL path and builds a JSON file from the information it receives. The front page of the webapp (/smartmirror) will get the JSON file from the URL (/json) and update the webapp via ajax. 

<h1>Coming Soon</h1>
A comprehensive setup guide and detailed explaination of the full range of features.

As this version written in C++ use pistache.io there is no support for running this app on a windows server. There is however a Python version of the Smart Mirror using Flask which runs on any device supporting Python and Flask. I will finalise this version soon.
