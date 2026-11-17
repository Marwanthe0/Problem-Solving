const PptxGenJS = require('pptxgenjs');

const pptx = new PptxGenJS();

pptx.author = 'Shafikul Islam Marwan';
pptx.title = 'Computer Security - CLO2 Presentation';
pptx.subject = 'Evaluating Security Risks and Managing Information Security';

const C = {
  darkBg: '1B2A4A', accent: '2E86AB', teal: '36B37E', lightBg: 'F0F4F8',
  white: 'FFFFFF', black: '1A1A2E', dGray: '3D3D5C', lGray: 'E8ECF1',
  orange: 'E8734A', red: 'E74C3C', green: '27AE60', yellow: 'F39C12', purple: '9B59B6',
};

function hdr(slide, title, num) {
  slide.background = { color: C.white };
  slide.addShape(pptx.shapes.RECTANGLE, { x:0, y:0, w:10, h:0.6, fill:{color:C.darkBg} });
  slide.addText(title, { x:0.5, y:0.05, w:8, h:0.5, fontSize:18, bold:true, color:C.white, fontFace:'Calibri' });
  if(num) slide.addText(num, { x:8.8, y:0.05, w:1, h:0.5, fontSize:12, color:C.teal, fontFace:'Calibri', align:'right' });
  slide.addShape(pptx.shapes.RECTANGLE, { x:0, y:5.33, w:10, h:0.17, fill:{color:C.accent} });
  return slide;
}

// SLIDE 1 - Title
let s1 = pptx.addSlide(); s1.background = {color:C.darkBg};
s1.addText('Computer Security', { x:0.8,y:0.6,w:8.4,h:1, fontSize:36, fontFace:'Calibri', bold:true, color:C.white });
s1.addText('CLO2 — Evaluating Security Risks & Managing Information Security', { x:0.8,y:1.5,w:8.4,h:0.6, fontSize:16, fontFace:'Calibri', color:C.accent });
s1.addShape(pptx.shapes.RECTANGLE, { x:0.8,y:2.3,w:2,h:0.05, fill:{color:C.teal} });
s1.addText([
  {text:'Presented by:\n', options:{fontSize:11, color:C.lGray}},
  {text:'Shafikul Islam Marwan\n', options:{fontSize:16, bold:true, color:C.white}},
  {text:'ID: 220121  |  Reg: 2201020\n', options:{fontSize:12, color:C.lGray}},
  {text:'Dept. of CSE, JUST', options:{fontSize:12, color:C.lGray}},
], { x:0.8,y:2.6,w:4.5,h:1.6, valign:'top' });
s1.addText([
  {text:'Presented to:\n', options:{fontSize:11, color:C.lGray}},
  {text:'Dr. Engr. Md. Arif Rahman\n', options:{fontSize:14, bold:true, color:C.white}},
  {text:'Assistant Professor\n', options:{fontSize:11, color:C.lGray}},
  {text:'Department of CSE, JUST', options:{fontSize:11, color:C.lGray}},
], { x:5.5,y:2.6,w:4,h:1.6, valign:'top' });
s1.addText('Course Code: 4105', { x:0.8,y:4.6,w:8.4,h:0.4, fontSize:11, color:C.teal, fontFace:'Calibri' });

// SLIDE 2 - Agenda
let s2 = hdr(pptx.addSlide(), 'Topics Covered');
const agenda = [
  ['01','Risk Management — Process & Objectives'],['02','Identifying & Classifying Information Assets'],
  ['03','Threat Identification & Risk Components'],['04','Risk Analysis — Qualitative & Quantitative'],
  ['05','Risk Evaluation & Treatment Options'],['06','Security Controls — Preventive, Detective, Corrective'],
  ['07','Information Security Governance'],['08','ISMS & ISO/IEC 27001 Framework'],
  ['09','Security Policies, Standards & Procedures'],['10','Security Evaluation — Audits & Penetration Testing'],
];
agenda.forEach((a,i) => {
  let y = 0.9 + i*0.42;
  s2.addText(a[0], { x:0.6,y,w:0.5,h:0.35, fontSize:12, bold:true, color:C.accent, fontFace:'Calibri', align:'center', fill:{color:C.lightBg}, shape:pptx.shapes.ROUNDED_RECTANGLE, rectRadius:0.05 });
  s2.addText(a[1], { x:1.3,y,w:7.5,h:0.35, fontSize:13, color:C.dGray, fontFace:'Calibri', valign:'middle' });
});

// SLIDE 3 - Risk Management Overview
let s3 = hdr(pptx.addSlide(), 'Risk Management — Overview', '01');
s3.addText('What is Risk Management?', { x:0.6,y:0.8,w:8.5,h:0.4, fontSize:15, bold:true, color:C.accent, fontFace:'Calibri' });
s3.addText('A structured methodology for identifying potential threats, assessing their severity, selecting appropriate countermeasures, and continuously monitoring for emerging risks.', { x:0.6,y:1.2,w:8.5,h:0.5, fontSize:11, color:C.dGray, fontFace:'Calibri' });
s3.addText('Core Objectives', { x:0.6,y:1.9,w:8.5,h:0.35, fontSize:14, bold:true, color:C.darkBg, fontFace:'Calibri' });
['Catalog all valuable assets, associated threats, and known vulnerabilities',
 'Prioritize risks based on potential impact and likelihood of occurrence',
 'Minimize losses while maintaining operational continuity',
 'Establish a cycle of continuous monitoring and improvement'].forEach((o,i) => {
  s3.addText('\u25b8  '+o, { x:0.8,y:2.35+i*0.38,w:8.3,h:0.35, fontSize:11, color:C.dGray, fontFace:'Calibri' });
});
s3.addText('Real-World Scenario', { x:0.6,y:3.95,w:8.5,h:0.35, fontSize:13, bold:true, color:C.orange, fontFace:'Calibri' });
s3.addText('Consider a university storing student records on a central server. Key risks include unauthorized access, grade tampering, and hardware failure. Without risk management, these threats remain unaddressed until an incident occurs.', { x:0.6,y:4.3,w:8.5,h:0.7, fontSize:11, color:C.dGray, fontFace:'Calibri', italic:true });

// SLIDE 4 - Risk Management Lifecycle
let s4 = hdr(pptx.addSlide(), 'The Risk Management Lifecycle', '02');
const stages = [
  {n:'1',t:'Establish Context',d:'Define scope, objectives, boundaries, and risk appetite.'},
  {n:'2',t:'Risk Identification',d:'Discover assets, threats, vulnerabilities, and existing controls.'},
  {n:'3',t:'Risk Analysis',d:'Assess each risk\'s likelihood and potential organizational impact.'},
  {n:'4',t:'Risk Evaluation',d:'Compare risk scores against acceptance thresholds and prioritize.'},
  {n:'5',t:'Risk Treatment',d:'Select strategy: avoid, mitigate, transfer, or accept each risk.'},
  {n:'6',t:'Monitor & Review',d:'Continuously track risks, control effectiveness, and emerging threats.'},
  {n:'7',t:'Communicate & Report',d:'Inform stakeholders of risks and duties.'},
];
stages.forEach((s,i) => {
  let y = 0.8+i*0.6;
  s4.addShape(pptx.shapes.OVAL, { x:0.6,y,w:0.4,h:0.4, fill:{color:C.accent} });
  s4.addText(s.n, { x:0.6,y,w:0.4,h:0.4, fontSize:13, bold:true, color:C.white, fontFace:'Calibri', align:'center', valign:'middle' });
  s4.addText(s.t, { x:1.2,y,w:2.5,h:0.4, fontSize:12, bold:true, color:C.darkBg, fontFace:'Calibri', valign:'middle' });
  s4.addText(s.d, { x:3.7,y,w:5.8,h:0.4, fontSize:11, color:C.dGray, fontFace:'Calibri', valign:'middle' });
});

// SLIDE 5 - Information Assets
let s5 = hdr(pptx.addSlide(), 'Identifying Information Assets', '03');
const assets = [
  {t:'Data Assets',d:'Student records, financial data, research databases, contracts, IP'},
  {t:'Hardware & Software',d:'Servers, workstations, routers; OS, applications, database systems'},
  {t:'Network Infrastructure',d:'Switches, firewalls, cabling, wireless access points, VPN gateways'},
  {t:'Human Resources',d:'System admins, security officers, employees, contractors'},
  {t:'Physical Facilities',d:'Data centers, server rooms, office buildings, backup sites'},
  {t:'Services',d:'Cloud platforms, email hosting, DNS, payment gateways, ISPs'},
];
assets.forEach((a,i) => {
  let col=i<3?0:1, row=i%3, x=0.5+col*4.7, y=0.85+row*1.4;
  s5.addShape(pptx.shapes.ROUNDED_RECTANGLE, { x,y,w:4.3,h:1.2, fill:{color:C.lightBg}, rectRadius:0.1, line:{color:C.lGray,width:0.5} });
  s5.addText(a.t, { x:x+0.2,y:y+0.1,w:3.9,h:0.4, fontSize:13, bold:true, color:C.accent, fontFace:'Calibri' });
  s5.addText(a.d, { x:x+0.2,y:y+0.55,w:3.9,h:0.5, fontSize:10, color:C.dGray, fontFace:'Calibri' });
});

// SLIDE 6 - Asset Classification & Tracking
let s6 = hdr(pptx.addSlide(), 'Asset Classification & Inventory Management', '04');
s6.addText('Classification Levels', { x:0.6,y:0.8,w:4,h:0.35, fontSize:14, bold:true, color:C.darkBg, fontFace:'Calibri' });
[{l:'Public',c:C.green,d:'Freely shareable \u2014 e.g., university website content'},
 {l:'Internal',c:C.yellow,d:'Organization-only \u2014 e.g., internal memos'},
 {l:'Confidential',c:C.orange,d:'Restricted access \u2014 e.g., student personal details'},
 {l:'Top Secret',c:C.red,d:'Highest sensitivity \u2014 e.g., admin credentials'}].forEach((cl,i) => {
  let y=1.25+i*0.55;
  s6.addShape(pptx.shapes.ROUNDED_RECTANGLE, { x:0.7,y,w:1.3,h:0.4, fill:{color:cl.c}, rectRadius:0.05 });
  s6.addText(cl.l, { x:0.7,y,w:1.3,h:0.4, fontSize:10, bold:true, color:C.white, fontFace:'Calibri', align:'center', valign:'middle' });
  s6.addText(cl.d, { x:2.2,y,w:2.8,h:0.4, fontSize:10, color:C.dGray, fontFace:'Calibri', valign:'middle' });
});
s6.addText('Asset Tracking Steps', { x:5.2,y:0.8,w:4.3,h:0.35, fontSize:14, bold:true, color:C.darkBg, fontFace:'Calibri' });
[{s:'1. Inventory',d:'Catalog every asset \u2014 servers, databases, apps, labs'},
 {s:'2. Assign Owners',d:'Designate a responsible person for each asset'},
 {s:'3. Classify',d:'Group assets by sensitivity and criticality'},
 {s:'4. Valuate',d:'Assess financial, operational, and legal value'},
 {s:'5. Map Dependencies',d:'Identify interdependencies between systems'},
 {s:'6. Periodic Review',d:'Update records when assets or configs change'}].forEach((t,i) => {
  let y=1.25+i*0.58;
  s6.addText(t.s, { x:5.3,y,w:4,h:0.25, fontSize:11, bold:true, color:C.accent, fontFace:'Calibri' });
  s6.addText(t.d, { x:5.3,y:y+0.22,w:4,h:0.25, fontSize:10, color:C.dGray, fontFace:'Calibri' });
});

// SLIDE 7 - Risk Components & Threats
let s7 = hdr(pptx.addSlide(), 'Risk Components & Threat Categories', '05');
s7.addText('Risk = Threat \u00d7 Vulnerability \u00d7 Impact', { x:0.6,y:0.75,w:8.5,h:0.4, fontSize:16, bold:true, color:C.orange, fontFace:'Calibri', align:'center' });
[{t:'Asset',d:'Anything of value \u2014 a database, server, or reputation',c:C.accent},
 {t:'Threat',d:'Potential cause of harm \u2014 attackers, malware, disasters',c:C.orange},
 {t:'Vulnerability',d:'Exploitable weakness \u2014 weak passwords, unpatched systems',c:C.red},
 {t:'Impact',d:'Consequence \u2014 financial loss, data breach, downtime',c:C.teal}].forEach((r,i) => {
  let x=0.4+i*2.35;
  s7.addShape(pptx.shapes.ROUNDED_RECTANGLE, { x,y:1.3,w:2.15,h:1.5, fill:{color:C.lightBg}, rectRadius:0.1, line:{color:r.c,width:1.5} });
  s7.addText(r.t, { x,y:1.4,w:2.15,h:0.4, fontSize:13, bold:true, color:r.c, fontFace:'Calibri', align:'center' });
  s7.addText(r.d, { x:x+0.1,y:1.85,w:1.95,h:0.8, fontSize:10, color:C.dGray, fontFace:'Calibri', align:'center' });
});
s7.addText('Types of Threats', { x:0.6,y:3.1,w:8.5,h:0.35, fontSize:14, bold:true, color:C.darkBg, fontFace:'Calibri' });
[{t:'Human',e:'Phishing, social engineering, insider misuse, password attacks'},
 {t:'Technical',e:'Hardware crashes, software bugs, network outages'},
 {t:'Environmental',e:'Floods, earthquakes, fires, power surges'},
 {t:'Organizational',e:'Missing policies, untrained staff, poor access control'}].forEach((th,i) => {
  let x=0.4+i*2.35;
  s7.addText(th.t, { x,y:3.55,w:2.15,h:0.3, fontSize:11, bold:true, color:C.accent, fontFace:'Calibri', align:'center' });
  s7.addText(th.e, { x:x+0.05,y:3.85,w:2.1,h:0.8, fontSize:9, color:C.dGray, fontFace:'Calibri', align:'center' });
});

// SLIDE 8 - Risk Identification Methods
let s8 = hdr(pptx.addSlide(), 'Methods for Identifying Risks', '06');
[{t:'Asset-Based Analysis',d:'Begin from critical assets and determine what could compromise each one.'},
 {t:'Vulnerability Scanning',d:'Use automated tools to detect outdated software, open ports, and weak credentials.'},
 {t:'Security Auditing',d:'Systematically verify that existing policies and controls are properly implemented.'},
 {t:'Stakeholder Interviews',d:'Consult IT staff, managers, and end users to surface overlooked risks.'},
 {t:'Historical Incident Review',d:'Analyze past breaches and near-misses to identify recurring patterns.'},
 {t:'Threat Intelligence Feeds',d:'Monitor industry reports and advisories for newly discovered attack vectors.'}].forEach((m,i) => {
  let col=i<3?0:1, row=i%3, x=0.5+col*4.7, y=0.85+row*1.4;
  s8.addShape(pptx.shapes.ROUNDED_RECTANGLE, { x,y,w:4.3,h:1.2, fill:{color:col===0?C.lightBg:'F5F0E8'}, rectRadius:0.1 });
  s8.addText(m.t, { x:x+0.2,y:y+0.15,w:3.9,h:0.35, fontSize:13, bold:true, color:C.accent, fontFace:'Calibri' });
  s8.addText(m.d, { x:x+0.2,y:y+0.55,w:3.9,h:0.5, fontSize:10, color:C.dGray, fontFace:'Calibri' });
});

// SLIDE 9 - Quantitative & Qualitative Analysis
let s9 = hdr(pptx.addSlide(), 'Quantitative & Qualitative Risk Analysis', '07');
s9.addText('Quantitative Approach', { x:0.6,y:0.8,w:4.2,h:0.35, fontSize:14, bold:true, color:C.accent, fontFace:'Calibri' });
s9.addText('Uses numerical values and financial metrics for precise measurement.', { x:0.6,y:1.15,w:4.2,h:0.35, fontSize:10, color:C.dGray, fontFace:'Calibri' });
[{l:'Single Loss Expectancy',f:'SLE = Asset Value (AV) \u00d7 Exposure Factor (EF)'},
 {l:'Annual Loss Expectancy',f:'ALE = SLE \u00d7 Annual Rate of Occurrence (ARO)'}].forEach((fm,i) => {
  s9.addShape(pptx.shapes.ROUNDED_RECTANGLE, { x:0.6,y:1.65+i*0.75,w:4.2,h:0.6, fill:{color:C.lightBg}, rectRadius:0.05 });
  s9.addText(fm.l, { x:0.8,y:1.68+i*0.75,w:3.8,h:0.25, fontSize:10, bold:true, color:C.darkBg, fontFace:'Calibri' });
  s9.addText(fm.f, { x:0.8,y:1.93+i*0.75,w:3.8,h:0.25, fontSize:10, color:C.accent, fontFace:'Calibri', italic:true });
});
s9.addShape(pptx.shapes.ROUNDED_RECTANGLE, { x:0.6,y:3.3,w:4.2,h:1, fill:{color:'FFF8E1'}, rectRadius:0.05, line:{color:C.orange,width:0.75} });
s9.addText('Example: Server worth 5,00,000 TK; EF = 40%\nSLE = 5,00,000 \u00d7 0.4 = 2,00,000 TK\nARO = 0.25 (once per 4 years)\nALE = 2,00,000 \u00d7 0.25 = 50,000 TK/year', { x:0.75,y:3.35,w:3.9,h:0.9, fontSize:10, color:C.dGray, fontFace:'Calibri' });

s9.addText('Qualitative Approach', { x:5.2,y:0.8,w:4.3,h:0.35, fontSize:14, bold:true, color:C.teal, fontFace:'Calibri' });
s9.addText('Uses descriptive scales (Low, Medium, High, Critical) for rapid assessment. Faster but inherently subjective.', { x:5.2,y:1.15,w:4.3,h:0.5, fontSize:10, color:C.dGray, fontFace:'Calibri' });
s9.addText('Risk Matrix: R = Likelihood \u00d7 Impact', { x:5.2,y:1.75,w:4.3,h:0.3, fontSize:11, bold:true, color:C.darkBg, fontFace:'Calibri' });

const mC = [
  [C.green,C.green,C.yellow,C.yellow,C.red],
  [C.green,C.yellow,C.yellow,C.red,C.red],
  [C.yellow,C.yellow,C.red,C.red,'C0392B'],
  [C.yellow,C.red,C.red,'C0392B','C0392B'],
  [C.red,C.red,'C0392B','C0392B',C.purple],
];
const mV = [['1','2','3','4','5'],['2','4','6','8','10'],['3','6','9','12','15'],['4','8','12','16','20'],['5','10','15','20','25']];
for(let r=0;r<5;r++) for(let c=0;c<5;c++) {
  let xP=5.5+c*0.6, yP=2.15+(4-r)*0.42;
  s9.addShape(pptx.shapes.RECTANGLE, { x:xP,y:yP,w:0.55,h:0.38, fill:{color:mC[r][c]} });
  s9.addText(mV[r][c], { x:xP,y:yP,w:0.55,h:0.38, fontSize:9, bold:true, color:C.white, fontFace:'Calibri', align:'center', valign:'middle' });
}
s9.addText('1\u20134 Low  |  5\u20139 Med  |  10\u201315 High  |  16\u201325 Critical', { x:5.2,y:4.4,w:4.3,h:0.3, fontSize:9, color:C.dGray, fontFace:'Calibri', align:'center' });

// SLIDE 10 - Risk Register
let s10 = hdr(pptx.addSlide(), 'Sample Risk Register', '08');
const hdrOpt = { bold:true, color:'FFFFFF', fill:{color:C.darkBg}, fontSize:10, fontFace:'Calibri', align:'center' };
const cellOpt = { fontSize:10, fontFace:'Calibri' };
s10.addTable([
  [{text:'Risk ID',options:hdrOpt},{text:'Asset',options:hdrOpt},{text:'Threat',options:hdrOpt},{text:'Vulnerability',options:hdrOpt},{text:'Rating',options:hdrOpt}],
  [{text:'R-01',options:{...cellOpt,align:'center'}},{text:'Student Database',options:cellOpt},{text:'External Hacker',options:cellOpt},{text:'Weak authentication',options:cellOpt},{text:'Critical',options:{...cellOpt,align:'center',bold:true,color:'C0392B'}}],
  [{text:'R-02',options:{...cellOpt,align:'center'}},{text:'Web Application',options:cellOpt},{text:'Malware Injection',options:cellOpt},{text:'Outdated CMS',options:cellOpt},{text:'High',options:{...cellOpt,align:'center',bold:true,color:C.red}}],
  [{text:'R-03',options:{...cellOpt,align:'center'}},{text:'Backup Server',options:cellOpt},{text:'Hardware Failure',options:cellOpt},{text:'No redundancy',options:cellOpt},{text:'Medium',options:{...cellOpt,align:'center',bold:true,color:C.yellow}}],
  [{text:'R-04',options:{...cellOpt,align:'center'}},{text:'HR Records',options:cellOpt},{text:'Insider Threat',options:cellOpt},{text:'Excessive permissions',options:cellOpt},{text:'High',options:{...cellOpt,align:'center',bold:true,color:C.red}}],
], { x:0.5,y:1,w:9, colW:[0.8,2,2,2.4,1], border:{type:'solid',color:C.lGray,pt:0.5}, rowH:[0.45,0.5,0.5,0.5,0.5], autoPage:false });
s10.addText('A risk register is a living document \u2014 updated whenever new risks surface or existing controls change.', { x:0.6,y:3.9,w:8.5,h:0.4, fontSize:11, italic:true, color:C.dGray, fontFace:'Calibri' });

// SLIDE 11 - Risk Treatment
let s11 = hdr(pptx.addSlide(), 'Risk Treatment Strategies', '09');
[{t:'Avoidance',d:'Eliminate the risk entirely by discontinuing the activity.',e:'Stop using an insecure third-party service.',c:C.red},
 {t:'Mitigation',d:'Reduce risk likelihood or impact through implementing safeguards.',e:'Deploy MFA and real-time login monitoring.',c:C.accent},
 {t:'Transfer / Sharing',d:'Shift the financial burden to a third party such as an insurer.',e:'Purchase cyber-liability insurance.',c:C.teal},
 {t:'Acceptance',d:'Formally acknowledge a low-priority risk and document the decision.',e:'Accept minor UI bugs in a non-critical internal tool.',c:C.yellow}].forEach((tr,i) => {
  let col=i%2, row=Math.floor(i/2), x=0.4+col*4.7, y=0.85+row*2.1;
  s11.addShape(pptx.shapes.ROUNDED_RECTANGLE, { x,y,w:4.3,h:1.85, fill:{color:C.lightBg}, rectRadius:0.1, line:{color:tr.c,width:1.5} });
  s11.addText(tr.t, { x:x+0.2,y:y+0.1,w:3.9,h:0.4, fontSize:15, bold:true, color:tr.c, fontFace:'Calibri' });
  s11.addText(tr.d, { x:x+0.2,y:y+0.55,w:3.9,h:0.55, fontSize:10, color:C.dGray, fontFace:'Calibri' });
  s11.addText('Example: '+tr.e, { x:x+0.2,y:y+1.15,w:3.9,h:0.45, fontSize:10, italic:true, color:C.dGray, fontFace:'Calibri' });
});

// SLIDE 12 - Residual Risk
let s12 = hdr(pptx.addSlide(), 'After Treatment \u2014 Residual Risk', '10');
s12.addText('Inherent Risk vs Residual Risk', { x:0.6,y:0.8,w:8.5,h:0.4, fontSize:15, bold:true, color:C.accent, fontFace:'Calibri' });
s12.addText('Inherent risk is the exposure before any controls are applied. Residual risk is what remains after treatment. No system can eliminate all risk \u2014 the goal is to reduce it to an acceptable level.', { x:0.6,y:1.2,w:8.5,h:0.6, fontSize:11, color:C.dGray, fontFace:'Calibri' });
s12.addText('Treatment Plan Components', { x:0.6,y:2,w:8.5,h:0.35, fontSize:14, bold:true, color:C.darkBg, fontFace:'Calibri' });
['Identified risks and selected treatment strategies','Specific controls to be implemented','Responsible owners and allocated resources','Implementation deadlines and milestones','Expected residual risk after treatment','Management sign-off and approval'].forEach((p,i) => {
  s12.addText('\u2726  '+p, { x:0.8,y:2.45+i*0.37,w:8.3,h:0.3, fontSize:11, color:C.dGray, fontFace:'Calibri' });
});
s12.addText('Acceptance Thresholds', { x:0.6,y:4.75,w:8.5,h:0.3, fontSize:12, bold:true, color:C.orange, fontFace:'Calibri' });
s12.addText('Low \u2192 Manager   |   Medium \u2192 Dept Head   |   High \u2192 Senior Mgmt   |   Critical \u2192 Treat Now', { x:0.6,y:5,w:8.5,h:0.3, fontSize:10, color:C.dGray, fontFace:'Calibri' });

// SLIDE 13 - Types of Controls
let s13 = hdr(pptx.addSlide(), 'Types of Security Controls', '11');
[{t:'Preventive Controls',d:'Stop security incidents before they can happen.',e:'Access controls, encryption, firewalls, security awareness training, strong password policies',c:C.accent},
 {t:'Detective Controls',d:'Identify incidents that are occurring or have just occurred.',e:'Intrusion detection systems, security logging, network monitoring, anomaly detection, CCTV',c:C.orange},
 {t:'Corrective Controls',d:'Limit damage and restore normal operations after an incident.',e:'Data restoration from backups, incident response procedures, patch management, disaster recovery',c:C.teal}].forEach((ct,i) => {
  let y=0.85+i*1.45;
  s13.addShape(pptx.shapes.ROUNDED_RECTANGLE, { x:0.5,y,w:9,h:1.25, fill:{color:C.lightBg}, rectRadius:0.1, line:{color:ct.c,width:1.5} });
  s13.addText(ct.t, { x:0.7,y:y+0.1,w:3.5,h:0.35, fontSize:14, bold:true, color:ct.c, fontFace:'Calibri' });
  s13.addText(ct.d, { x:0.7,y:y+0.45,w:8.6,h:0.3, fontSize:11, color:C.dGray, fontFace:'Calibri' });
  s13.addText('Examples: '+ct.e, { x:0.7,y:y+0.75,w:8.6,h:0.35, fontSize:10, italic:true, color:C.dGray, fontFace:'Calibri' });
});

// SLIDE 14 - Security Governance
let s14 = hdr(pptx.addSlide(), 'Information Security Governance', '12');
s14.addText('Governance is the system by which an organization directs, controls, and oversees its information security strategy.', { x:0.6,y:0.75,w:8.5,h:0.5, fontSize:12, italic:true, color:C.accent, fontFace:'Calibri' });
[{t:'Leadership & Direction',d:'Board and executives approve strategy, allocate resources, and define risk appetite.'},
 {t:'Accountability',d:'Clear roles for security teams, asset owners, managers, and end users.'},
 {t:'Strategic Alignment',d:'Security objectives tied directly to business goals and regulatory requirements.'},
 {t:'Oversight & Review',d:'Regular review of performance metrics, incident reports, and compliance status.'},
 {t:'Culture of Security',d:'Foster responsible behavior through training, awareness, and continuous improvement.'}].forEach((g,i) => {
  s14.addText('\u25b8  '+g.t, { x:0.6,y:1.4+i*0.7,w:3,h:0.3, fontSize:12, bold:true, color:C.darkBg, fontFace:'Calibri' });
  s14.addText(g.d, { x:3.5,y:1.4+i*0.7,w:6,h:0.5, fontSize:10, color:C.dGray, fontFace:'Calibri' });
});
s14.addShape(pptx.shapes.ROUNDED_RECTANGLE, { x:0.5,y:4.9,w:9,h:0.4, fill:{color:C.lightBg}, rectRadius:0.05 });
s14.addText('Governance sets the DIRECTION  \u2022  Management handles the EXECUTION', { x:0.5,y:4.9,w:9,h:0.4, fontSize:11, bold:true, color:C.accent, fontFace:'Calibri', align:'center', valign:'middle' });

// SLIDE 15 - ISMS & ISO 27001
let s15 = hdr(pptx.addSlide(), 'ISMS & ISO/IEC 27001 Framework', '13');
s15.addText('An Information Security Management System (ISMS) is a coordinated framework of policies, processes, people, and technology used to manage and reduce information security risks systematically.', { x:0.6,y:0.75,w:8.5,h:0.5, fontSize:11, color:C.dGray, fontFace:'Calibri' });
[{p:'Plan',d:'Define scope, assess risks, set objectives, write policies.',c:C.accent},
 {p:'Do',d:'Implement controls, deploy safeguards, run awareness programs.',c:C.teal},
 {p:'Check',d:'Monitor, measure, audit, and review performance.',c:C.orange},
 {p:'Act',d:'Correct weaknesses, improve, and update the ISMS.',c:C.red}].forEach((pd,i) => {
  let x=0.4+i*2.35;
  s15.addShape(pptx.shapes.ROUNDED_RECTANGLE, { x,y:1.5,w:2.15,h:1.4, fill:{color:pd.c}, rectRadius:0.1 });
  s15.addText(pd.p, { x,y:1.55,w:2.15,h:0.4, fontSize:16, bold:true, color:C.white, fontFace:'Calibri', align:'center' });
  s15.addText(pd.d, { x:x+0.1,y:2,w:1.95,h:0.75, fontSize:10, color:C.white, fontFace:'Calibri', align:'center' });
});
s15.addText('ISO/IEC 27001:2022 \u2014 Annex A: 93 Controls in 4 Domains', { x:0.6,y:3.2,w:8.5,h:0.35, fontSize:13, bold:true, color:C.darkBg, fontFace:'Calibri' });
[{d:'37 Organizational',e:'Policies, risk management, supplier security, incident handling'},
 {d:'8 People',e:'Screening, awareness programs, NDAs, disciplinary processes'},
 {d:'14 Physical',e:'Secure areas, entry controls, equipment protection, disposal'},
 {d:'34 Technological',e:'Access control, encryption, anti-malware, logging, network security'}].forEach((a,i) => {
  let x=0.4+i*2.35;
  s15.addShape(pptx.shapes.ROUNDED_RECTANGLE, { x,y:3.65,w:2.15,h:1.3, fill:{color:C.lightBg}, rectRadius:0.08 });
  s15.addText(a.d, { x:x+0.1,y:3.7,w:1.95,h:0.35, fontSize:11, bold:true, color:C.accent, fontFace:'Calibri', align:'center' });
  s15.addText(a.e, { x:x+0.1,y:4.1,w:1.95,h:0.7, fontSize:9, color:C.dGray, fontFace:'Calibri', align:'center' });
});

// SLIDE 16 - ISMS Roadmap
let s16 = hdr(pptx.addSlide(), 'ISMS Implementation Roadmap', '14');
[{p:'Phase 1\u20132',t:'Initiation',d:'Secure management commitment and define ISMS scope.'},
 {p:'Phase 3\u20134',t:'Foundation',d:'Draft security policies, inventory and classify all assets.'},
 {p:'Phase 5\u20136',t:'Risk Work',d:'Conduct risk assessment, develop and approve treatment plans.'},
 {p:'Phase 7',t:'Control Deployment',d:'Implement organizational, people, physical, and technical controls.'},
 {p:'Phase 8\u20139',t:'Verification',d:'Deliver staff training, then perform internal audits.'},
 {p:'Phase 10',t:'Continuous Improvement',d:'Management review and ongoing ISMS enhancement.'}].forEach((r,i) => {
  let y=0.8+i*0.72;
  s16.addShape(pptx.shapes.ROUNDED_RECTANGLE, { x:0.5,y,w:1.4,h:0.55, fill:{color:C.accent}, rectRadius:0.05 });
  s16.addText(r.p, { x:0.5,y,w:1.4,h:0.55, fontSize:10, bold:true, color:C.white, fontFace:'Calibri', align:'center', valign:'middle' });
  s16.addText(r.t, { x:2.1,y,w:2,h:0.55, fontSize:12, bold:true, color:C.darkBg, fontFace:'Calibri', valign:'middle' });
  s16.addText(r.d, { x:4.1,y,w:5.4,h:0.55, fontSize:11, color:C.dGray, fontFace:'Calibri', valign:'middle' });
});

// SLIDE 17 - Security Policies
let s17 = hdr(pptx.addSlide(), 'Security Policies, Standards & Procedures', '15');
[{t:'Policy',w:'High-level, management-approved directive stating security intentions.',f:'Defines WHAT must be done and WHY.',c:C.accent},
 {t:'Standard',w:'Specific mandatory requirements that implement policy goals.',f:'Defines the RULES \u2014 e.g., "Use AES-256 for data encryption."',c:C.teal},
 {t:'Procedure',w:'Step-by-step instructions for carrying out a particular task.',f:'Defines HOW \u2014 detailed, repeatable, mandatory actions.',c:C.orange},
 {t:'Guideline',w:'Recommended best practices and advice \u2014 not mandatory.',f:'Offers SUGGESTIONS for optimal outcomes.',c:C.purple}].forEach((p,i) => {
  let col=i%2, row=Math.floor(i/2), x=0.4+col*4.7, y=0.85+row*2.1;
  s17.addShape(pptx.shapes.ROUNDED_RECTANGLE, { x,y,w:4.3,h:1.85, fill:{color:C.lightBg}, rectRadius:0.1, line:{color:p.c,width:1.5} });
  s17.addText(p.t, { x:x+0.2,y:y+0.1,w:3.9,h:0.4, fontSize:15, bold:true, color:p.c, fontFace:'Calibri' });
  s17.addText(p.w, { x:x+0.2,y:y+0.55,w:3.9,h:0.55, fontSize:10, color:C.dGray, fontFace:'Calibri' });
  s17.addText(p.f, { x:x+0.2,y:y+1.15,w:3.9,h:0.45, fontSize:10, bold:true, color:p.c, fontFace:'Calibri' });
});

// SLIDE 18 - Security Evaluation
let s18 = hdr(pptx.addSlide(), 'Security Evaluation Methods', '16');
[{t:'Security Audit',d:'An independent, formal examination of an organization\'s security posture against established standards (such as ISO 27001). Verifies compliance and identifies gaps.'},
 {t:'Vulnerability Assessment',d:'Automated and manual scanning to discover known weaknesses \u2014 outdated software, misconfigurations, open ports. Produces a prioritized list to remediate.'},
 {t:'Penetration Testing',d:'Authorized simulation of real-world attacks to actively exploit vulnerabilities and test defenses. Demonstrates actual impact and validates control effectiveness.'}].forEach((e,i) => {
  let y=0.85+i*1.45;
  s18.addShape(pptx.shapes.ROUNDED_RECTANGLE, { x:0.5,y,w:9,h:1.25, fill:{color:C.lightBg}, rectRadius:0.1 });
  s18.addText(e.t, { x:0.7,y:y+0.1,w:8.6,h:0.35, fontSize:14, bold:true, color:C.accent, fontFace:'Calibri' });
  s18.addText(e.d, { x:0.7,y:y+0.5,w:8.6,h:0.65, fontSize:10, color:C.dGray, fontFace:'Calibri' });
});

// SLIDE 19 - Comparison Table
let s19 = hdr(pptx.addSlide(), 'Risk Management vs Governance vs ISMS', '17');
const ch = { bold:true, color:'FFFFFF', fill:{color:C.darkBg}, fontSize:11, fontFace:'Calibri', align:'center' };
const cc = { fontSize:10, fontFace:'Calibri' };
s19.addTable([
  [{text:'Aspect',options:ch},{text:'Risk Management',options:ch},{text:'Governance',options:ch},{text:'ISMS',options:ch}],
  [{text:'Purpose',options:{...cc,bold:true}},{text:'Identify, analyze, and treat risks',options:cc},{text:'Set direction and ensure accountability',options:cc},{text:'Systematically manage security',options:cc}],
  [{text:'Focus',options:{...cc,bold:true}},{text:'What can go wrong?',options:cc},{text:'Who is responsible?',options:cc},{text:'How is it done?',options:cc}],
  [{text:'Activities',options:{...cc,bold:true}},{text:'Identify \u2192 Analyze \u2192 Evaluate \u2192 Treat',options:cc},{text:'Strategy approval, oversight, compliance',options:cc},{text:'PDCA framework, documentation, audits',options:cc}],
  [{text:'Example',options:{...cc,bold:true}},{text:'Assessing database exposure',options:{...cc,italic:true}},{text:'Board approving a security policy',options:{...cc,italic:true}},{text:'ISO 27001 certification process',options:{...cc,italic:true}}],
], { x:0.5,y:1,w:9, colW:[1.5,2.5,2.5,2.5], border:{type:'solid',color:C.lGray,pt:0.5}, rowH:[0.5,0.6,0.6,0.6,0.6], autoPage:false });

// SLIDE 20 - Key Takeaways
let s20 = hdr(pptx.addSlide(), 'Key Takeaways', '18');
['Risk management is a continuous cycle \u2014 identify, analyze, evaluate, treat, and monitor.',
 'Understanding your assets is the foundation of effective security.',
 'Treat risks through avoidance, mitigation, transfer, or informed acceptance.',
 'Security controls should be preventive, detective, and corrective.',
 'Governance provides strategic direction; ISMS operationalizes it.',
 'ISO/IEC 27001 provides the gold standard framework for managing information security.'].forEach((t,i) => {
  let y=0.85+i*0.7;
  s20.addShape(pptx.shapes.ROUNDED_RECTANGLE, { x:0.5,y,w:9,h:0.55, fill:{color:i%2===0?C.lightBg:C.white}, rectRadius:0.08 });
  s20.addText('\u25b8  '+t, { x:0.7,y,w:8.6,h:0.55, fontSize:12, color:C.dGray, fontFace:'Calibri', valign:'middle' });
});

// SLIDE 21 - Thank You
let s21 = pptx.addSlide(); s21.background = {color:C.darkBg};
s21.addText('Thank You', { x:0.5,y:1.2,w:9,h:1.2, fontSize:48, bold:true, color:C.white, fontFace:'Calibri', align:'center' });
s21.addShape(pptx.shapes.RECTANGLE, { x:3.5,y:2.5,w:3,h:0.05, fill:{color:C.teal} });
s21.addText('Shafikul Islam Marwan  |  ID: 220121', { x:0.5,y:2.8,w:9,h:0.5, fontSize:16, color:C.accent, fontFace:'Calibri', align:'center' });
s21.addText('Department of CSE, JUST', { x:0.5,y:3.3,w:9,h:0.4, fontSize:13, color:C.lGray, fontFace:'Calibri', align:'center' });
s21.addText('Questions & Discussion', { x:0.5,y:4,w:9,h:0.4, fontSize:14, italic:true, color:C.teal, fontFace:'Calibri', align:'center' });

// SAVE
const outputPath = 'C:/Problem Solving/LightOj/DP Problems/CLO2_Marwan_220121.pptx';
pptx.writeFile({ fileName: outputPath })
  .then(() => console.log('SUCCESS: Presentation saved to ' + outputPath))
  .catch(err => console.error('ERROR:', err));
