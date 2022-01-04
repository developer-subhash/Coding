/**

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% "ModernCV" CV and Cover Letter
% LaTeX Template
% Version 1.1 (9/12/12)
%
% This template has been downloaded from:
% http://www.LaTeXTemplates.com
%
% Original author:
% Xavier Danaux (xdanaux@gmail.com)
%
% License:
% CC BY-NC-SA 3.0 (http://creativecommons.org/licenses/by-nc-sa/3.0/)
%
% Important note:
% This template requires the moderncv.cls and .sty files to be in the same 
% directory as this .tex file. These files provide the resume style and themes 
% used for structuring the document.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%----------------------------------------------------------------------------------------
%	PACKAGES AND OTHER DOCUMENT CONFIGURATIONS
%----------------------------------------------------------------------------------------

\documentclass[11pt,a4paper,sans]{moderncv} % Font sizes: 10, 11, or 12; paper sizes: a4paper, letterpaper, a5paper, legalpaper, executivepaper or landscape; font families: sans or roman

\moderncvstyle{classic} % CV theme - options include: 'casual' (default), 'classic', 'oldstyle' and 'banking'
\moderncvcolor{blue} % CV color - options include: 'blue' (default), 'orange', 'green', 'red', 'purple', 'grey' and 'black'

\usepackage{lipsum} % Used for inserting dummy 'Lorem ipsum' text into the template
\usepackage[utf8]{inputenc}
\usepackage[scale=0.85]{geometry} % Reduce document margins

\usepackage{fontspec}

\newfontface\lserif{Liberation Serif}
\newcommand{\Csh}{C{\lserif\#}}
%\setlength{\hintscolumnwidth}{3cm} % Uncomment to change the width of the dates column
%\setlength{\makecvtitlenamewidth}{10cm} % For the 'classic' style, uncomment to adjust the width of the space allocated to your name

%----------------------------------------------------------------------------------------
%	NAME AND CONTACT INFORMATION SECTION
%----------------------------------------------------------------------------------------

\firstname{Subhash} % Your first name
\familyname{Kumar Suman} % Your last name

% All information in this block is optional, comment out any lines you don't need
\title{Curriculum Vitae}
%\address{Rte gremda km 4,5 Av Mongi Slim}{Sfax, Tunisie BP 3062}
\mobile{(+91) 8210286733}
%\phone{(000) 111 1112}
%\fax{(000) 111 1113}
\email{subhash.krsuman.cse19@itbhu.ac.in}
%\homepage{staff.org.edu/~jsmith}{staff.org.edu/$\sim$jsmith} % The first argument is %the url for the clickable link, the second argument is the url displayed in the %template - this allows special characters to be displayed such as the tilde in this %example
%\extrainfo{24 ans}
%\photo[70pt][0.4pt]{picture} % The first bracket is the picture height, the second is %the thickness of the frame around the picture (0pt for no frame)
%\quote{ \Large ing\'enieur informatique industrielle }

%----------------------------------------------------------------------------------------

\begin{document}

\makecvtitle % Print the CV title

%----------------------------------------------------------------------------------------
%	EDUCATION SECTION
%----------------------------------------------------------------------------------------

\section{Education}

\cventry{2019-present}{B-Tech in Computer Science and Engineering }{}{}{}{ CPI: 8.91, Indian Institute Of Technology(BHU), Varanasi, India}  % Arguments not required can be left empty
\cventry{2018-2019}{IIT Jee Preparation}{}{}{}{CRL Rank: 2494 in IIT Jee Advance 2019 Exam}
\cventry{2016-2018}{Class 12th CBSE}{}{}{}{76.8\% , Progressive Central High School, Patsa, Samastipur, Bihar}
\cventry{2016}{Class 10th CBSE}{}{}{}{CGPA 10.0, Progressive Central High School, Patsa, Samastipur, Bihar}


%----------------------------------------------------------------------------------------
%	WORK EXPERIENCE SECTION
%----------------------------------------------------------------------------------------

\section{Projects}

\cventry{April--Present 2021}{Social Website}{}{}{}{use of NodeJs, Express, MongoDB}
{}

\cventry{April--Present 2021}{Cart React App , Movie List App}{}{}{}{use of React and Redux}
{}

\cventry{Jan--April 2021}{Anomaly Detection in a real time video}{}{}{}{use of keras as deep learning framework, CNN, one class SVM, OpenCV, VGG19 }
{}

\cventry{Oct--Nov 2020}{Jobhub}{}{}{}{A simple website created using django as backend web-framework  }
{}


%----------------------------------------------------------------------------------------
%	COMPUTER SKILLS SECTION
%----------------------------------------------------------------------------------------

\section{Skills}

\cventry{--}{Proficient in}{}{}{}{C, C++, Javascript, Html, Css, NodeJs, MongoDB, React, Github }
{}

\cventry{--}{Can Work With}{}{}{}{Python Django, Mysql }
{}

\section{Achievements}
\cventry{--}{Codeforces}{}{}{}{Became specialist Coder at Codeforces, Max Rating: 1415 }
{}

\cventry{--}{IIT Jee Advance}{}{}{}{AIR 2494 among 250,000 students}
{}

\cventry{--}{IIT Jee Main}{}{}{}{AIR 5603 among 1.5 Million Students }
{}


%----------------------------------------------------------------------------------------
%	LANGUAGES SECTION
%----------------------------------------------------------------------------------------

\section{Position Of Responsibilty}
\cventry{2020--2021}{Publicity Team Member, Codefest 2020, IIT BHU, Varansi}{}{}{}{Part of Publicity Team For Annual Coding Festival 2020 Edition of Computer Science and Engg. Department }
{}


%----------------------------------------------------------------------------------------
%	INTERESTS SECTION
%----------------------------------------------------------------------------------------
%\bigskip

%\section{Interest }
 


%----------------------------------------------------------------------------------------
%	COVER LETTER
%----------------------------------------------------------------------------------------

% To remove the cover letter, comment out this entire block

%\clearpage

%\recipient{HR Departmnet}{Corporation\\123 Pleasant Lane\\12345 City, State} % Letter recipient
%\date{\today} % Letter date
%\opening{Dear Sir or Madam,} % Opening greeting
%\closing{Sincerely yours,} % Closing phrase
%\enclosure[Attached]{curriculum vit\ae{}} % List of enclosed documents

%\makelettertitle % Print letter title

%\lipsum[1-3] % Dummy text

%\makeletterclosing % Print letter signature

%----------------------------------------------------------------------------------------

\end{document}