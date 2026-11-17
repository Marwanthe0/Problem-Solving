const pptxgen = require('pptxgenjs');

const pres = new pptxgen();
pres.layout = 'LAYOUT_16x9';

// Define Color Palette
const COLORS = {
  primary: '0B2545',     // Deep Navy
  secondary: '134074',   // Slate Blue
  accent: '0077B6',      // Tech Blue
  highlight: 'E63946',   // Crimson accent
  success: '2A9D8F',     // Teal / Green
  bgLight: 'F4F6F9',     // Off-white / light slate
  cardBg: 'FFFFFF',      // White
  cardBorder: 'D0D7DE',  // Subtle border
  textDark: '1D2D44',    // Dark Navy Charcoal
  textMuted: '57606A',   // Cool Grey
  white: 'FFFFFF'
};

function addHeader(slide, title, category) {
  // Top bar background
  slide.addShape(pres.ShapeType.rect, {
    x: 0, y: 0, w: '100%', h: 0.95,
    fill: { color: COLORS.primary }
  });

  // Category / Subject Tag
  slide.addText(category.toUpperCase(), {
    x: 0.6, y: 0.12, w: 9.0, h: 0.25,
    fontSize: 10, bold: true, color: '90E0EF', fontFace: 'Calibri'
  });

  // Slide Title
  slide.addText(title, {
    x: 0.6, y: 0.38, w: 11.5, h: 0.45,
    fontSize: 20, bold: true, color: COLORS.white, fontFace: 'Calibri'
  });

  // Footer bar
  slide.addShape(pres.ShapeType.rect, {
    x: 0, y: 7.15, w: '100%', h: 0.35,
    fill: { color: 'E9ECEF' }
  });

  slide.addText("Course: CSE 4105 (CLO2) | Computer Security", {
    x: 0.6, y: 7.2, w: 6.0, h: 0.25,
    fontSize: 9, color: COLORS.textMuted, fontFace: 'Calibri'
  });

  slide.addText("Shafikul Islam Marwan (ID: 220121, Reg: 2201020) | Dept. of CSE, JUST", {
    x: 6.8, y: 7.2, w: 5.8, h: 0.25,
    fontSize: 9, align: 'right', color: COLORS.textMuted, fontFace: 'Calibri'
  });
}

// -------------------------------------------------------------
// SLIDE 1: Title Slide
// -------------------------------------------------------------
{
  const slide = pres.addSlide();
  slide.background = { color: COLORS.primary };

  // Decorative Accent Bar
  slide.addShape(pres.ShapeType.rect, {
    x: 0.8, y: 0.9, w: 0.15, h: 2.2,
    fill: { color: '00B4D8' }
  });

  // Super-title
  slide.addText("COURSE: COMPUTER SECURITY (CSE 4105) • CLO 2", {
    x: 1.1, y: 0.9, w: 10.5, h: 0.35,
    fontSize: 13, bold: true, color: '90E0EF', fontFace: 'Calibri'
  });

  // Main Title
  slide.addText("Information Security Risk Management\n& Governance Frameworks", {
    x: 1.1, y: 1.3, w: 11.0, h: 1.5,
    fontSize: 32, bold: true, color: COLORS.white, fontFace: 'Calibri', lineSpacing: 38
  });

  // Subtitle
  slide.addText("A Systematic Approach to Asset Valuation, Threat Assessment, Controls & ISMS Alignment", {
    x: 1.1, y: 2.9, w: 10.8, h: 0.45,
    fontSize: 14, italic: true, color: 'CAF0F8', fontFace: 'Calibri'
  });

  // Card 1: Presented By
  slide.addShape(pres.ShapeType.roundRect, {
    x: 1.1, y: 3.8, w: 5.2, h: 2.8,
    fill: { color: '134074' }, line: { color: '0077B6', width: 1.5 }, rectRadius: 0.1
  });

  slide.addText("PRESENTED BY", {
    x: 1.4, y: 4.0, w: 4.5, h: 0.3,
    fontSize: 11, bold: true, color: '90E0EF', fontFace: 'Calibri'
  });

  slide.addText("Shafikul Islam Marwan", {
    x: 1.4, y: 4.35, w: 4.6, h: 0.45,
    fontSize: 19, bold: true, color: COLORS.white, fontFace: 'Calibri'
  });

  slide.addText("Student ID: 220121\nRegistration No: 2201020\nDepartment of Computer Science & Engineering\nJashore University of Science and Technology (JUST)", {
    x: 1.4, y: 4.85, w: 4.6, h: 1.4,
    fontSize: 12, color: 'E0E1DD', fontFace: 'Calibri', lineSpacing: 18
  });

  // Card 2: Presented To
  slide.addShape(pres.ShapeType.roundRect, {
    x: 6.8, y: 3.8, w: 5.3, h: 2.8,
    fill: { color: '134074' }, line: { color: '0077B6', width: 1.5 }, rectRadius: 0.1
  });

  slide.addText("PRESENTED TO", {
    x: 7.1, y: 4.0, w: 4.6, h: 0.3,
    fontSize: 11, bold: true, color: '90E0EF', fontFace: 'Calibri'
  });

  slide.addText("Dr. Engr. Md. Arif Rahman", {
    x: 7.1, y: 4.35, w: 4.8, h: 0.45,
    fontSize: 19, bold: true, color: COLORS.white, fontFace: 'Calibri'
  });

  slide.addText("Assistant Professor\nDepartment of Computer Science & Engineering\nJashore University of Science and Technology (JUST)", {
    x: 7.1, y: 4.85, w: 4.8, h: 1.4,
    fontSize: 12, color: 'E0E1DD', fontFace: 'Calibri', lineSpacing: 18
  });
}

// -------------------------------------------------------------
// SLIDE 2: Presentation Architecture / Roadmap
// -------------------------------------------------------------
{
  const slide = pres.addSlide();
  slide.background = { color: COLORS.bgLight };
  addHeader(slide, "Presentation Roadmap & Agenda", "Structure Overview");

  const topics = [
    { num: "01", title: "Risk Management Lifecycle", desc: "6-phase continuous framework based on ISO 31000 standards" },
    { num: "02", title: "Information Asset Identification", desc: "Taxonomy, valuation techniques, ownership & data classification" },
    { num: "03", title: "Threat, Vulnerability & Risk", desc: "Risk equation mechanics and qualitative vs quantitative assessments" },
    { num: "04", title: "Risk Treatment Strategies", desc: "Avoidance, mitigation, transference, acceptance & residual risk" },
    { num: "05", title: "Security Governance & Controls", desc: "Strategic oversight, RACI boundaries & 3-tier control taxonomy" },
    { num: "06", title: "ISMS & ISO/IEC 27001", desc: "PDCA Deming cycle and the 4 modern control themes (93 controls)" },
    { num: "07", title: "Policy, Standards & Procedures", desc: "Governance hierarchy from strategic intent to daily execution" },
    { num: "08", title: "Evaluation & Case Study", desc: "Audits, pen-tests, metrics & an applied academic portal scenario" }
  ];

  topics.forEach((t, i) => {
    const col = i % 4;
    const row = Math.floor(i / 4);
    const x = 0.6 + col * 3.05;
    const y = 1.3 + row * 2.75;

    slide.addShape(pres.ShapeType.roundRect, {
      x, y, w: 2.85, h: 2.5,
      fill: { color: COLORS.cardBg }, line: { color: COLORS.cardBorder, width: 1.2 }, rectRadius: 0.1
    });

    slide.addShape(pres.ShapeType.roundRect, {
      x: x + 0.15, y: y + 0.15, w: 0.65, h: 0.45,
      fill: { color: COLORS.secondary }, rectRadius: 0.05
    });

    slide.addText(t.num, {
      x: x + 0.15, y: y + 0.15, w: 0.65, h: 0.45,
      fontSize: 13, bold: true, color: COLORS.white, align: 'center', valign: 'middle'
    });

    slide.addText(t.title, {
      x: x + 0.15, y: y + 0.75, w: 2.55, h: 0.65,
      fontSize: 13, bold: true, color: COLORS.textDark, fontFace: 'Calibri'
    });

    slide.addText(t.desc, {
      x: x + 0.15, y: y + 1.45, w: 2.55, h: 0.95,
      fontSize: 11, color: COLORS.textMuted, fontFace: 'Calibri', lineSpacing: 14
    });
  });
}

// -------------------------------------------------------------
// SLIDE 3: The Risk Management Lifecycle
// -------------------------------------------------------------
{
  const slide = pres.addSlide();
  slide.background = { color: COLORS.bgLight };
  addHeader(slide, "The Information Security Risk Management Lifecycle", "Core Foundation");

  // Introductory banner
  slide.addShape(pres.ShapeType.roundRect, {
    x: 0.6, y: 1.2, w: 12.1, h: 0.75,
    fill: { color: 'E2EAFC' }, line: { color: 'B6CCFE', width: 1 }, rectRadius: 0.08
  });
  slide.addText("Core Principle: Security risk management is an ongoing, cyclical process—not a one-time checklist. It dynamically adapts as technologies, business models, and threat landscapes evolve.", {
    x: 0.8, y: 1.25, w: 11.7, h: 0.65,
    fontSize: 12, bold: true, color: COLORS.primary, fontFace: 'Calibri'
  });

  const steps = [
    { step: "1. Scope & Context", sub: "Define boundaries, legal obligations, regulatory mandates, and risk tolerance limits." },
    { step: "2. Asset & Threat ID", sub: "Catalog critical assets; identify threat vectors, vulnerabilities, and current safeguards." },
    { step: "3. Risk Analysis", sub: "Estimate probability and operational/financial impact using quantitative or qualitative models." },
    { step: "4. Risk Evaluation", sub: "Compare calculated risks against defined risk appetite to establish treatment priorities." },
    { step: "5. Risk Treatment", sub: "Select and deploy optimal remediation: Mitigate, Avoid, Transfer, or Formally Accept." },
    { step: "6. Monitor & Audit", sub: "Continuously review control effectiveness, monitor emergent threats, and report to stakeholders." }
  ];

  steps.forEach((s, idx) => {
    const x = 0.6 + (idx % 3) * 4.1;
    const y = 2.2 + Math.floor(idx / 3) * 2.3;

    slide.addShape(pres.ShapeType.roundRect, {
      x, y, w: 3.9, h: 2.1,
      fill: { color: COLORS.cardBg }, line: { color: COLORS.cardBorder, width: 1.2 }, rectRadius: 0.08
    });

    // Top accent indicator
    slide.addShape(pres.ShapeType.rect, {
      x, y, w: 3.9, h: 0.1,
      fill: { color: idx < 2 ? COLORS.accent : idx < 4 ? COLORS.secondary : COLORS.success }
    });

    slide.addText(s.step, {
      x: x + 0.25, y: y + 0.25, w: 3.4, h: 0.45,
      fontSize: 14, bold: true, color: COLORS.textDark, fontFace: 'Calibri'
    });

    slide.addText(s.sub, {
      x: x + 0.25, y: y + 0.75, w: 3.4, h: 1.2,
      fontSize: 11.5, color: COLORS.textMuted, fontFace: 'Calibri', lineSpacing: 15
    });
  });
}

// -------------------------------------------------------------
// SLIDE 4: Information Assets: Categorization & Ownership
// -------------------------------------------------------------
{
  const slide = pres.addSlide();
  slide.background = { color: COLORS.bgLight };
  addHeader(slide, "Information Asset Identification & Valuation", "Asset Management");

  // Left Column: Asset Categories
  slide.addShape(pres.ShapeType.roundRect, {
    x: 0.6, y: 1.25, w: 5.9, h: 5.65,
    fill: { color: COLORS.cardBg }, line: { color: COLORS.cardBorder, width: 1.2 }, rectRadius: 0.1
  });

  slide.addText("Asset Taxonomy (What Must Be Defended)", {
    x: 0.9, y: 1.45, w: 5.3, h: 0.4,
    fontSize: 14, bold: true, color: COLORS.secondary, fontFace: 'Calibri'
  });

  const categories = [
    { title: "Data & Intellectual Property", eg: "Research papers, student records, credentials, financial logs" },
    { title: "Software & Application Systems", eg: "Student portals, grading engines, ERP, OS, databases" },
    { title: "Hardware & Network Equipment", eg: "Blade servers, routers, firewalls, edge IoT switches, SAN storage" },
    { title: "Human Capital & Knowledge", eg: "System administrators, research specialists, institutional workflows" },
    { title: "Facilities & Critical Utilities", eg: "Campus server rooms, power distribution, HVAC cooling infrastructure" }
  ];

  categories.forEach((c, idx) => {
    slide.addText(`•  ${c.title}`, {
      x: 0.9, y: 1.95 + idx * 0.95, w: 5.3, h: 0.35,
      fontSize: 12.5, bold: true, color: COLORS.textDark, fontFace: 'Calibri'
    });
    slide.addText(`    ${c.eg}`, {
      x: 0.9, y: 2.3 + idx * 0.95, w: 5.3, h: 0.45,
      fontSize: 11, italic: true, color: COLORS.textMuted, fontFace: 'Calibri'
    });
  });

  // Right Column: Asset Inventory & Management Lifecycle
  slide.addShape(pres.ShapeType.roundRect, {
    x: 6.8, y: 1.25, w: 5.9, h: 5.65,
    fill: { color: COLORS.cardBg }, line: { color: COLORS.cardBorder, width: 1.2 }, rectRadius: 0.1
  });

  slide.addText("Asset Governance Lifecycle", {
    x: 7.1, y: 1.45, w: 5.3, h: 0.4,
    fontSize: 14, bold: true, color: COLORS.secondary, fontFace: 'Calibri'
  });

  const steps = [
    { step: "1. Exhaustive Discovery", text: "Maintain automated network scanning and hardware/software inventory (CMDB)." },
    { step: "2. Explicit Custodianship", text: "Assign an accountable Asset Owner who approves access and recovery objectives (RTO/RPO)." },
    { step: "3. Dependency Mapping", text: "Chart critical upstream/downstream dependencies (e.g., if DB fails, Portal halts)." },
    { step: "4. Data Classification", text: "Categorize into Public, Internal, Confidential, and Secret based on business impact." }
  ];

  steps.forEach((s, idx) => {
    slide.addText(s.step, {
      x: 7.1, y: 1.95 + idx * 1.2, w: 5.3, h: 0.35,
      fontSize: 12.5, bold: true, color: COLORS.primary, fontFace: 'Calibri'
    });
    slide.addText(s.text, {
      x: 7.1, y: 2.3 + idx * 1.2, w: 5.3, h: 0.7,
      fontSize: 11, color: COLORS.textMuted, fontFace: 'Calibri', lineSpacing: 14
    });
  });
}

// -------------------------------------------------------------
// SLIDE 5: Anatomy of Risk: Threats & Vulnerabilities
// -------------------------------------------------------------
{
  const slide = pres.addSlide();
  slide.background = { color: COLORS.bgLight };
  addHeader(slide, "Anatomy of Security Risk: Threats, Vulnerabilities & Impacts", "Risk Formulation");

  // Formula Banner
  slide.addShape(pres.ShapeType.roundRect, {
    x: 0.6, y: 1.2, w: 12.1, h: 0.95,
    fill: { color: COLORS.secondary }, rectRadius: 0.08
  });
  slide.addText("Risk Formula:  Security Risk = Threat Vector × Vulnerability × Asset Impact", {
    x: 0.8, y: 1.35, w: 11.7, h: 0.35,
    fontSize: 16, bold: true, color: COLORS.white, align: 'center', fontFace: 'Calibri'
  });
  slide.addText("A vulnerability without an active threat poses zero imminent risk; a threat without an exploitable vulnerability cannot compromise the asset.", {
    x: 0.8, y: 1.75, w: 11.7, h: 0.3,
    fontSize: 11, italic: true, color: '90E0EF', align: 'center', fontFace: 'Calibri'
  });

  const cards = [
    {
      title: "Threat Agents & Vectors",
      color: 'E63946',
      items: [
        "Human: Spear-phishing, malicious insiders, credential stuffing",
        "Technical: Ransomware, zero-day exploits, DDoS floods",
        "Environmental: Power outages, cooling failures, seismic hazards",
        "Supply Chain: Insecure 3rd-party libraries, compromised vendor APIs"
      ]
    },
    {
      title: "Vulnerabilities (Weaknesses)",
      color: 'F4A261',
      items: [
        "Software: Unpatched kernel CVEs, SQLi/XSS, default credentials",
        "Configuration: Misconfigured cloud S3 buckets, exposed ports",
        "Architectural: Single points of failure (SPOF), unsegmented networks",
        "Operational: Lack of multi-factor authentication (MFA), no incident runbooks"
      ]
    },
    {
      title: "Impact Dimensions",
      color: '2A9D8F',
      items: [
        "Confidentiality: Unauthorized disclosure of proprietary records",
        "Integrity: Tampering of grades, balance sheets, or audit trails",
        "Availability: Prolonged downtime of essential student services",
        "Legal & Brand: Regulatory fines, breach notifications, reputational loss"
      ]
    }
  ];

  cards.forEach((c, idx) => {
    const x = 0.6 + idx * 4.1;
    slide.addShape(pres.ShapeType.roundRect, {
      x, y: 2.4, w: 3.9, h: 4.5,
      fill: { color: COLORS.cardBg }, line: { color: COLORS.cardBorder, width: 1.2 }, rectRadius: 0.08
    });

    slide.addShape(pres.ShapeType.rect, {
      x, y: 2.4, w: 3.9, h: 0.12,
      fill: { color: c.color }
    });

    slide.addText(c.title, {
      x: x + 0.2, y: 2.65, w: 3.5, h: 0.45,
      fontSize: 14, bold: true, color: COLORS.textDark, fontFace: 'Calibri'
    });

    c.items.forEach((item, itemIdx) => {
      slide.addText(`• ${item}`, {
        x: x + 0.2, y: 3.2 + itemIdx * 0.95, w: 3.5, h: 0.85,
        fontSize: 11, color: COLORS.textMuted, fontFace: 'Calibri', lineSpacing: 14
      });
    });
  });
}

// -------------------------------------------------------------
// SLIDE 6: Qualitative vs. Quantitative Risk Assessment
// -------------------------------------------------------------
{
  const slide = pres.addSlide();
  slide.background = { color: COLORS.bgLight };
  addHeader(slide, "Risk Assessment Methodologies: Qualitative & Quantitative", "Evaluation Models");

  // Left Column: Qualitative & Risk Matrix
  slide.addShape(pres.ShapeType.roundRect, {
    x: 0.6, y: 1.25, w: 5.9, h: 5.65,
    fill: { color: COLORS.cardBg }, line: { color: COLORS.cardBorder, width: 1.2 }, rectRadius: 0.1
  });

  slide.addText("Qualitative Analysis (Subjective Scoring)", {
    x: 0.9, y: 1.45, w: 5.3, h: 0.35,
    fontSize: 14, bold: true, color: COLORS.secondary, fontFace: 'Calibri'
  });

  slide.addText("• Uses categorical scales (Low, Medium, High, Critical) based on consensus.\n• Fast and intuitive for prioritizing organizational security posture.\n• Formula: Risk Level = Likelihood Index × Consequence Score.", {
    x: 0.9, y: 1.85, w: 5.3, h: 0.85,
    fontSize: 11, color: COLORS.textMuted, fontFace: 'Calibri', lineSpacing: 15
  });

  // Small Matrix Table representation
  const matrixData = [
    [{ text: "Likelihood \\ Impact", options: { bold: true, fill: '134074', color: 'FFFFFF' } },
     { text: "Low (1)", options: { bold: true, fill: '134074', color: 'FFFFFF' } },
     { text: "Med (2)", options: { bold: true, fill: '134074', color: 'FFFFFF' } },
     { text: "High (3)", options: { bold: true, fill: '134074', color: 'FFFFFF' } }],
    [{ text: "High (3)", options: { bold: true } }, { text: "Medium (3)", options: { fill: 'F4A261' } }, { text: "High (6)", options: { fill: 'E76F51', color: 'FFFFFF' } }, { text: "Critical (9)", options: { fill: 'E63946', color: 'FFFFFF' } }],
    [{ text: "Med (2)", options: { bold: true } }, { text: "Low (2)", options: { fill: 'E9C46A' } }, { text: "Medium (4)", options: { fill: 'F4A261' } }, { text: "High (6)", options: { fill: 'E76F51', color: 'FFFFFF' } }],
    [{ text: "Low (1)", options: { bold: true } }, { text: "Low (1)", options: { fill: '2A9D8F', color: 'FFFFFF' } }, { text: "Low (2)", options: { fill: 'E9C46A' } }, { text: "Medium (3)", options: { fill: 'F4A261' } }]
  ];

  slide.addTable(matrixData, {
    x: 0.9, y: 2.85, w: 5.3, h: 2.1,
    colW: [1.7, 1.2, 1.2, 1.2],
    fontSize: 10, align: 'center', valign: 'middle'
  });

  slide.addText("Action Priority: Score 6-9 requires urgent executive remediation; Score 1-2 is typically accepted.", {
    x: 0.9, y: 5.2, w: 5.3, h: 0.6,
    fontSize: 10.5, italic: true, color: COLORS.textDark, fontFace: 'Calibri'
  });

  // Right Column: Quantitative Analysis
  slide.addShape(pres.ShapeType.roundRect, {
    x: 6.8, y: 1.25, w: 5.9, h: 5.65,
    fill: { color: COLORS.cardBg }, line: { color: COLORS.cardBorder, width: 1.2 }, rectRadius: 0.1
  });

  slide.addText("Quantitative Analysis (Monetary Precision)", {
    x: 7.1, y: 1.45, w: 5.3, h: 0.35,
    fontSize: 14, bold: true, color: COLORS.secondary, fontFace: 'Calibri'
  });

  slide.addText("Computes hard financial figures to justify the Return on Security Investment (ROSI).", {
    x: 7.1, y: 1.85, w: 5.3, h: 0.4,
    fontSize: 11, color: COLORS.textMuted, fontFace: 'Calibri'
  });

  const formulas = [
    { name: "Single Loss Expectancy (SLE)", formula: "SLE = Asset Value (AV) × Exposure Factor (EF)" },
    { name: "Annualized Loss Expectancy (ALE)", formula: "ALE = SLE × Annualized Rate of Occurrence (ARO)" },
    { name: "Cost-Benefit Calculation (CBC)", formula: "Net Savings = (ALE_pre - ALE_post) - Annual Safeguard Cost" }
  ];

  formulas.forEach((f, idx) => {
    slide.addText(f.name, {
      x: 7.1, y: 2.35 + idx * 0.9, w: 5.3, h: 0.28,
      fontSize: 11.5, bold: true, color: COLORS.primary, fontFace: 'Calibri'
    });
    slide.addShape(pres.ShapeType.rect, {
      x: 7.1, y: 2.65 + idx * 0.9, w: 5.3, h: 0.4,
      fill: { color: 'F0F4F8' }, line: { color: 'CBD5E1', width: 0.8 }
    });
    slide.addText(f.formula, {
      x: 7.2, y: 2.7, w: 5.1, h: 0.3,
      fontSize: 11, bold: true, color: COLORS.accent, fontFace: 'Calibri'
    });
  });

  // Concrete Example
  slide.addShape(pres.ShapeType.roundRect, {
    x: 7.1, y: 5.15, w: 5.3, h: 1.5,
    fill: { color: 'EBF5EE' }, line: { color: 'A3C9A8', width: 1 }, rectRadius: 0.05
  });
  slide.addText("Practical Example (University Central Database):", {
    x: 7.25, y: 5.25, w: 5.0, h: 0.25,
    fontSize: 11, bold: true, color: '1B4931', fontFace: 'Calibri'
  });
  slide.addText("• Asset Value (AV): 1,000,000 BDT | Exposure Factor (EF): 30% (Data corruption)\n• SLE = 1,000,000 × 0.30 = 300,000 BDT\n• Occurrence Rate (ARO): Once every 3 years (0.33/yr)\n• ALE = 300,000 × 0.33 = 100,000 BDT/year → Safeguard budget must not exceed 100,000 BDT/year.", {
    x: 7.25, y: 5.5, w: 5.0, h: 1.05,
    fontSize: 10, color: '1B4931', fontFace: 'Calibri', lineSpacing: 13
  });
}

// -------------------------------------------------------------
// SLIDE 7: The Four Risk Treatment Strategies
// -------------------------------------------------------------
{
  const slide = pres.addSlide();
  slide.background = { color: COLORS.bgLight };
  addHeader(slide, "Risk Treatment Strategies & Residual Risk Management", "Risk Response");

  const strategies = [
    {
      title: "Risk Mitigation (Reduction)",
      sub: "Active Safeguard Deployment",
      desc: "Implement engineering, administrative, and technological controls to reduce likelihood or impact to an acceptable threshold.",
      eg: "Deploying Multi-Factor Authentication (MFA), web application firewalls, immutable automated database backups.",
      color: '0077B6'
    },
    {
      title: "Risk Transference (Sharing)",
      sub: "Externalizing Financial Loss",
      desc: "Contractually shift potential financial consequences to a qualified third party without abdicating executive responsibility.",
      eg: "Purchasing comprehensive Cyber Liability Insurance policies; outsourcing cloud hosting to AWS with strict SLA warranties.",
      color: '2A9D8F'
    },
    {
      title: "Risk Avoidance (Termination)",
      sub: "Eliminating Exposure Entirely",
      desc: "Completely cease or redesign the operational activity that introduces the vulnerability when treatment costs exceed business value.",
      eg: "Retiring deprecated, unpatchable legacy Windows XP servers; discontinuing high-risk anonymous file upload endpoints.",
      color: 'E63946'
    },
    {
      title: "Risk Acceptance (Retention)",
      sub: "Documented Leadership Sign-off",
      desc: "Acknowledge and retain residual risk when it falls comfortably within the organizational risk appetite and remediation is cost-ineffective.",
      eg: "Accepting minor cosmetic UI error leaks that expose zero database credentials; formally logging signed approval in the Risk Register.",
      color: 'F4A261'
    }
  ];

  strategies.forEach((st, idx) => {
    const col = idx % 2;
    const row = Math.floor(idx / 2);
    const x = 0.6 + col * 6.2;
    const y = 1.3 + row * 2.8;

    slide.addShape(pres.ShapeType.roundRect, {
      x, y, w: 5.9, h: 2.55,
      fill: { color: COLORS.cardBg }, line: { color: COLORS.cardBorder, width: 1.2 }, rectRadius: 0.08
    });

    slide.addShape(pres.ShapeType.rect, {
      x, y, w: 0.15, h: 2.55,
      fill: { color: st.color }
    });

    slide.addText(st.title, {
      x: x + 0.35, y: y + 0.2, w: 5.3, h: 0.35,
      fontSize: 14, bold: true, color: COLORS.textDark, fontFace: 'Calibri'
    });

    slide.addText(st.sub.toUpperCase(), {
      x: x + 0.35, y: y + 0.55, w: 5.3, h: 0.25,
      fontSize: 9.5, bold: true, color: st.color, fontFace: 'Calibri'
    });

    slide.addText(st.desc, {
      x: x + 0.35, y: y + 0.85, w: 5.3, h: 0.75,
      fontSize: 11, color: COLORS.textMuted, fontFace: 'Calibri', lineSpacing: 14
    });

    slide.addText(`Example: ${st.eg}`, {
      x: x + 0.35, y: y + 1.65, w: 5.3, h: 0.75,
      fontSize: 10.5, italic: true, color: COLORS.secondary, fontFace: 'Calibri', lineSpacing: 13
    });
  });
}

// -------------------------------------------------------------
// SLIDE 8: Security Controls Taxonomy
// -------------------------------------------------------------
{
  const slide = pres.addSlide();
  slide.background = { color: COLORS.bgLight };
  addHeader(slide, "Taxonomy of Security Controls: Function & Mechanism", "Defense in Depth");

  // Top Section: Functional Classification
  slide.addShape(pres.ShapeType.roundRect, {
    x: 0.6, y: 1.25, w: 12.1, h: 2.7,
    fill: { color: COLORS.cardBg }, line: { color: COLORS.cardBorder, width: 1.2 }, rectRadius: 0.08
  });

  slide.addText("Classification by Chronological Function (When They Act)", {
    x: 0.9, y: 1.45, w: 11.5, h: 0.35,
    fontSize: 14, bold: true, color: COLORS.secondary, fontFace: 'Calibri'
  });

  const funcControls = [
    {
      title: "1. Preventive Controls",
      sub: "Block unauthorized activity before it manifests.",
      examples: "Zero-Trust network segmentation, least-privilege IAM roles, input sanitization, multi-factor authentication (MFA)."
    },
    {
      title: "2. Detective Controls",
      sub: "Identify active threats or intrusions in real time.",
      examples: "Continuous Security Information & Event Management (SIEM), automated IDS/IPS telemetry, file integrity monitoring."
    },
    {
      title: "3. Corrective Controls",
      sub: "Limit damage and restore operational baseline.",
      examples: "Disaster recovery failover, immutable snapshot restore, isolated incident response playbooks, automated quarantine."
    }
  ];

  funcControls.forEach((f, idx) => {
    const x = 0.9 + idx * 3.9;
    slide.addShape(pres.ShapeType.roundRect, {
      x, y: 1.9, w: 3.7, h: 1.85,
      fill: { color: 'F8FAFC' }, line: { color: 'E2E8F0', width: 1 }, rectRadius: 0.05
    });

    slide.addText(f.title, {
      x: x + 0.2, y: 2.05, w: 3.3, h: 0.3,
      fontSize: 12.5, bold: true, color: COLORS.primary, fontFace: 'Calibri'
    });

    slide.addText(f.sub, {
      x: x + 0.2, y: 2.4, w: 3.3, h: 0.45,
      fontSize: 10.5, color: COLORS.textDark, fontFace: 'Calibri'
    });

    slide.addText(f.examples, {
      x: x + 0.2, y: 2.85, w: 3.3, h: 0.75,
      fontSize: 10, italic: true, color: COLORS.textMuted, fontFace: 'Calibri', lineSpacing: 13
    });
  });

  // Bottom Section: Implementation Mechanism
  slide.addShape(pres.ShapeType.roundRect, {
    x: 0.6, y: 4.15, w: 12.1, h: 2.7,
    fill: { color: COLORS.cardBg }, line: { color: COLORS.cardBorder, width: 1.2 }, rectRadius: 0.08
  });

  slide.addText("Classification by Implementation Mechanism (How They Are Realized)", {
    x: 0.9, y: 4.35, w: 11.5, h: 0.35,
    fontSize: 14, bold: true, color: COLORS.secondary, fontFace: 'Calibri'
  });

  const mechControls = [
    { title: "Technical / Logical", desc: "Hardware and software controls: Firewalls, AES-256 encryption, hashing algorithms, honeypots." },
    { title: "Administrative / Managerial", desc: "Policies, procedures, periodic risk reviews, background checks, mandatory security awareness training." },
    { title: "Physical / Environmental", desc: "Biometric access gates, armed guards, CCTV surveillance, fire suppression, perimeter fencing." }
  ];

  mechControls.forEach((m, idx) => {
    const x = 0.9 + idx * 3.9;
    slide.addShape(pres.ShapeType.roundRect, {
      x, y: 4.8, w: 3.7, h: 1.85,
      fill: { color: 'F8FAFC' }, line: { color: 'E2E8F0', width: 1 }, rectRadius: 0.05
    });

    slide.addText(m.title, {
      x: x + 0.2, y: 4.95, w: 3.3, h: 0.3,
      fontSize: 12.5, bold: true, color: COLORS.secondary, fontFace: 'Calibri'
    });

    slide.addText(m.desc, {
      x: x + 0.2, y: 5.35, w: 3.3, h: 1.15,
      fontSize: 10.5, color: COLORS.textMuted, fontFace: 'Calibri', lineSpacing: 14
    });
  });
}

// -------------------------------------------------------------
// SLIDE 9: Information Security Governance
// -------------------------------------------------------------
{
  const slide = pres.addSlide();
  slide.background = { color: COLORS.bgLight };
  addHeader(slide, "Information Security Governance: Strategic Alignment & Oversight", "Governance");

  // Definition Box
  slide.addShape(pres.ShapeType.roundRect, {
    x: 0.6, y: 1.25, w: 12.1, h: 1.1,
    fill: { color: 'EBF2FA' }, line: { color: 'B6CCFE', width: 1 }, rectRadius: 0.08
  });

  slide.addText("What is Security Governance?", {
    x: 0.9, y: 1.35, w: 11.5, h: 0.3,
    fontSize: 13, bold: true, color: COLORS.primary, fontFace: 'Calibri'
  });

  slide.addText("The system of leadership, organizational structures, and managerial processes that direct and control security strategies, ensuring alignment with enterprise objectives, regulatory compliance, and risk appetite.", {
    x: 0.9, y: 1.68, w: 11.5, h: 0.55,
    fontSize: 11.5, color: COLORS.textDark, fontFace: 'Calibri'
  });

  // Comparison Cards
  // Left: Governance
  slide.addShape(pres.ShapeType.roundRect, {
    x: 0.6, y: 2.55, w: 5.9, h: 4.35,
    fill: { color: COLORS.cardBg }, line: { color: COLORS.cardBorder, width: 1.2 }, rectRadius: 0.08
  });

  slide.addShape(pres.ShapeType.rect, {
    x: 0.6, y: 2.55, w: 5.9, h: 0.45,
    fill: { color: COLORS.primary }
  });

  slide.addText("Governance (Strategic Oversight — Board & CISO)", {
    x: 0.8, y: 2.65, w: 5.5, h: 0.3,
    fontSize: 12, bold: true, color: COLORS.white, fontFace: 'Calibri'
  });

  const govPoints = [
    "Sets Strategic Direction: Decides what business objectives security must enable.",
    "Defines Risk Appetite: Approves organizational tolerance for operational risks.",
    "Allocates Capital & Resources: Approves security expenditure budgets and staffing.",
    "Ensures Accountability & Compliance: Enforces legal, contractual, and regulatory compliance (GDPR, ISO 27001).",
    "Evaluates Performance: Reviews audit reports, major incidents, and executive KPIs."
  ];

  govPoints.forEach((p, idx) => {
    slide.addText(`✔  ${p}`, {
      x: 0.9, y: 3.2 + idx * 0.72, w: 5.3, h: 0.65,
      fontSize: 11, color: COLORS.textDark, fontFace: 'Calibri', lineSpacing: 14
    });
  });

  // Right: Management
  slide.addShape(pres.ShapeType.roundRect, {
    x: 6.8, y: 2.55, w: 5.9, h: 4.35,
    fill: { color: COLORS.cardBg }, line: { color: COLORS.cardBorder, width: 1.2 }, rectRadius: 0.08
  });

  slide.addShape(pres.ShapeType.rect, {
    x: 6.8, y: 2.55, w: 5.9, h: 0.45,
    fill: { color: COLORS.secondary }
  });

  slide.addText("Management (Operational Execution — SecOps & IT Teams)", {
    x: 7.0, y: 2.65, w: 5.5, h: 0.3,
    fontSize: 12, bold: true, color: COLORS.white, fontFace: 'Calibri'
  });

  const mgmtPoints = [
    "Executes Directives: Builds, configures, and operates defensive infrastructure.",
    "Administers Daily Controls: Configures IAM permissions, firewall rule sets, and patches.",
    "Conducts Operations: Manages Security Operations Center (SOC) incident monitoring.",
    "Maintains Documentation: Drafts technical procedures, baseline hardening guides, and runbooks.",
    "Reports Metrics: Delivers patch compliance %, mean time to remediate (MTTR) to leadership."
  ];

  mgmtPoints.forEach((p, idx) => {
    slide.addText(`▶  ${p}`, {
      x: 7.1, y: 3.2 + idx * 0.72, w: 5.3, h: 0.65,
      fontSize: 11, color: COLORS.textDark, fontFace: 'Calibri', lineSpacing: 14
    });
  });
}

// -------------------------------------------------------------
// SLIDE 10: Information Security Management System (ISMS)
// -------------------------------------------------------------
{
  const slide = pres.addSlide();
  slide.background = { color: COLORS.bgLight };
  addHeader(slide, "Information Security Management System (ISMS) & ISO/IEC 27001", "ISMS Standards");

  // Top ISO 27001 Overview
  slide.addShape(pres.ShapeType.roundRect, {
    x: 0.6, y: 1.25, w: 12.1, h: 1.2,
    fill: { color: COLORS.cardBg }, line: { color: COLORS.cardBorder, width: 1.2 }, rectRadius: 0.08
  });

  slide.addText("ISO/IEC 27001:2022 Overview", {
    x: 0.9, y: 1.4, w: 11.5, h: 0.3,
    fontSize: 13, bold: true, color: COLORS.primary, fontFace: 'Calibri'
  });

  slide.addText("An ISMS is an institutionalized framework comprising policies, workflows, personnel controls, and tech safeguards to systematically manage information confidentiality, integrity, and availability. ISO 27001:2022 restructures security controls into 4 consolidated domains encompassing 93 total controls.", {
    x: 0.9, y: 1.72, w: 11.5, h: 0.65,
    fontSize: 11, color: COLORS.textMuted, fontFace: 'Calibri'
  });

  // PDCA Cycle 4 Columns
  const pdca = [
    { phase: "PLAN", title: "Establish Context & Scope", items: ["Identify stakeholder needs", "Perform risk assessment", "Draft Statement of Applicability (SoA)"], color: '0077B6' },
    { phase: "DO", title: "Implement & Operate", items: ["Deploy selected technical controls", "Allocate risk budgets", "Enforce staff awareness training"], color: '2A9D8F' },
    { phase: "CHECK", title: "Monitor & Audit", items: ["Conduct internal security audits", "Analyze SIEM metrics & incident logs", "Hold formal management reviews"], color: 'F4A261' },
    { phase: "ACT", title: "Correct & Continually Improve", items: ["Address identified non-conformities", "Update policies & hardening baselines", "Iterate risk treatment register"], color: 'E63946' }
  ];

  pdca.forEach((p, idx) => {
    const x = 0.6 + idx * 3.08;
    slide.addShape(pres.ShapeType.roundRect, {
      x, y: 2.65, w: 2.9, h: 4.25,
      fill: { color: COLORS.cardBg }, line: { color: COLORS.cardBorder, width: 1.2 }, rectRadius: 0.08
    });

    slide.addShape(pres.ShapeType.rect, {
      x, y: 2.65, w: 2.9, h: 0.5,
      fill: { color: p.color }
    });

    slide.addText(p.phase, {
      x, y: 2.7, w: 2.9, h: 0.4,
      fontSize: 14, bold: true, color: COLORS.white, align: 'center', fontFace: 'Calibri'
    });

    slide.addText(p.title, {
      x: x + 0.15, y: 3.3, w: 2.6, h: 0.55,
      fontSize: 12, bold: true, color: COLORS.textDark, fontFace: 'Calibri'
    });

    p.items.forEach((item, itemIdx) => {
      slide.addText(`• ${item}`, {
        x: x + 0.15, y: 3.95 + itemIdx * 0.9, w: 2.6, h: 0.8,
        fontSize: 10.5, color: COLORS.textMuted, fontFace: 'Calibri', lineSpacing: 13
      });
    });
  });
}

// -------------------------------------------------------------
// SLIDE 11: ISO 27001:2022 Four Control Domains
// -------------------------------------------------------------
{
  const slide = pres.addSlide();
  slide.background = { color: COLORS.bgLight };
  addHeader(slide, "ISO/IEC 27001:2022 Control Structure: The 4 Modern Themes", "Annex A Controls");

  const themes = [
    {
      theme: "Organizational Controls (37 Controls)",
      scope: "Governs administrative practices, supplier management, and strategic security operations.",
      controls: [
        "Information security policy formulation & regular review",
        "Asset management and acceptable use policies",
        "Information classification and labeling rules",
        "Supplier and cloud third-party security management",
        "Incident response orchestration & reporting pipelines"
      ],
      color: '0B2545'
    },
    {
      theme: "People Controls (8 Controls)",
      scope: "Addresses workforce security across the complete employee lifecycle.",
      controls: [
        "Pre-employment background verification and vetting",
        "Non-disclosure and confidentiality contractual terms",
        "Periodic mandatory security education and phishing training",
        "Disciplinary actions for intentional security violations",
        "Post-employment access revocation & asset recovery"
      ],
      color: '134074'
    },
    {
      theme: "Physical Controls (14 Controls)",
      scope: "Defends physical perimeters, data centers, and physical workplace security.",
      controls: [
        "Physical entry controls, biometrics, and visitor badging",
        "Equipment positioning and secure environmental protection",
        "Unattended workstation and Clean Desk / Clear Screen policy",
        "Secure storage and sanitized disposal of paper/media",
        "Protection against fire, water, and power fluctuations"
      ],
      color: '0077B6'
    },
    {
      theme: "Technological Controls (34 Controls)",
      scope: "Enforces technical safeguards across systems, applications, and networks.",
      controls: [
        "Role-Based Access Control (RBAC) and privileged access",
        "Data encryption at rest and in transit (AES-256, TLS 1.3)",
        "Secure software development lifecycle (SSDLC) & code review",
        "Network segregation, DMZ zoning, and egress filtering",
        "Centralized audit logging and real-time vulnerability scanning"
      ],
      color: '2A9D8F'
    }
  ];

  themes.forEach((t, idx) => {
    const col = idx % 2;
    const row = Math.floor(idx / 2);
    const x = 0.6 + col * 6.2;
    const y = 1.25 + row * 2.85;

    slide.addShape(pres.ShapeType.roundRect, {
      x, y, w: 5.9, h: 2.65,
      fill: { color: COLORS.cardBg }, line: { color: COLORS.cardBorder, width: 1.2 }, rectRadius: 0.08
    });

    slide.addShape(pres.ShapeType.rect, {
      x, y, w: 5.9, h: 0.4,
      fill: { color: t.color }
    });

    slide.addText(t.theme, {
      x: x + 0.2, y: y + 0.08, w: 5.5, h: 0.3,
      fontSize: 12, bold: true, color: COLORS.white, fontFace: 'Calibri'
    });

    slide.addText(t.scope, {
      x: x + 0.2, y: y + 0.48, w: 5.5, h: 0.45,
      fontSize: 10, italic: true, color: COLORS.textMuted, fontFace: 'Calibri'
    });

    t.controls.forEach((c, cIdx) => {
      slide.addText(`•  ${c}`, {
        x: x + 0.2, y: y + 0.95 + cIdx * 0.32, w: 5.5, h: 0.3,
        fontSize: 9.8, color: COLORS.textDark, fontFace: 'Calibri'
      });
    });
  });
}

// -------------------------------------------------------------
// SLIDE 12: Documentation Hierarchy: Policy, Standards, Procedures
// -------------------------------------------------------------
{
  const slide = pres.addSlide();
  slide.background = { color: COLORS.bgLight };
  addHeader(slide, "Security Documentation Hierarchy: Policy to Procedure", "Governance Artifacts");

  const docs = [
    {
      level: "POLICY",
      role: "Strategic Direction (What & Why)",
      nature: "Mandatory — Approved by Board / Senior Leadership",
      desc: "High-level statements establishing management intent, overarching goals, and fundamental organizational rules.",
      example: "Enterprise Access Control Policy: 'All university information assets must be protected against unauthorized disclosure and access shall be strictly role-based.'",
      color: '0B2545'
    },
    {
      level: "STANDARD",
      role: "Mandatory Baseline (The Metric / Threshold)",
      nature: "Mandatory — Enforced by Security & Compliance",
      desc: "Specific, measurable, and compulsory technical or configuration thresholds required to achieve policy compliance.",
      example: "Password & Cryptographic Standard: 'Passwords must contain ≥14 characters, require MFA, and all web traffic must terminate on TLS 1.3 using AES-256-GCM.'",
      color: '134074'
    },
    {
      level: "PROCEDURE",
      role: "Tactical Execution (How Step-by-Step)",
      nature: "Mandatory — Standard Operating Procedure (SOP)",
      desc: "Chronological, step-by-step technical instructions for carrying out operational tasks and administrative workflows.",
      example: "Employee Offboarding SOP: 'Step 1: Receive HR ticket. Step 2: Disable Active Directory account within 1 hour. Step 3: Revoke VPN tokens. Step 4: Archive inbox.'",
      color: '0077B6'
    },
    {
      level: "GUIDELINE",
      role: "Discretionary Advice (Recommended Best Practice)",
      nature: "Non-Mandatory — Advisory Best Practices",
      desc: "Flexible, suggested practices that help users make informed security decisions where strict standards cannot apply.",
      example: "Secure Telework Guideline: 'Staff are advised to angle their laptop screens away from public view and avoid unencrypted café Wi-Fi hotspots without corporate VPN.'",
      color: '2A9D8F'
    }
  ];

  docs.forEach((d, idx) => {
    const y = 1.25 + idx * 1.42;

    slide.addShape(pres.ShapeType.roundRect, {
      x: 0.6, y, w: 12.1, h: 1.3,
      fill: { color: COLORS.cardBg }, line: { color: COLORS.cardBorder, width: 1.2 }, rectRadius: 0.08
    });

    slide.addShape(pres.ShapeType.roundRect, {
      x: 0.8, y: y + 0.15, w: 1.8, h: 1.0,
      fill: { color: d.color }, rectRadius: 0.05
    });

    slide.addText(d.level, {
      x: 0.8, y: y + 0.25, w: 1.8, h: 0.35,
      fontSize: 14, bold: true, color: COLORS.white, align: 'center', fontFace: 'Calibri'
    });

    slide.addText(d.nature.split('—')[0].trim(), {
      x: 0.8, y: y + 0.65, w: 1.8, h: 0.35,
      fontSize: 9, bold: true, color: '90E0EF', align: 'center', fontFace: 'Calibri'
    });

    slide.addText(d.role, {
      x: 2.8, y: y + 0.15, w: 9.6, h: 0.3,
      fontSize: 12.5, bold: true, color: COLORS.textDark, fontFace: 'Calibri'
    });

    slide.addText(d.desc, {
      x: 2.8, y: y + 0.45, w: 9.6, h: 0.35,
      fontSize: 10.5, color: COLORS.textMuted, fontFace: 'Calibri'
    });

    slide.addText(d.example, {
      x: 2.8, y: y + 0.8, w: 9.6, h: 0.38,
      fontSize: 10, italic: true, color: COLORS.secondary, fontFace: 'Calibri'
    });
  });
}

// -------------------------------------------------------------
// SLIDE 13: Information Security Evaluation & Assurance
// -------------------------------------------------------------
{
  const slide = pres.addSlide();
  slide.background = { color: COLORS.bgLight };
  addHeader(slide, "Information Security Evaluation & Assurance Mechanisms", "Assurance & Testing");

  const methods = [
    {
      title: "Vulnerability Assessment (VA)",
      type: "Automated Flaw Discovery",
      focus: "Breadth over Depth",
      points: [
        "Automated tools (Nessus, OpenVAS, Qualys) scan networks and code repositories.",
        "Detects missing patches, open ports, default passwords, and obsolete library versions.",
        "Output: Ranked list of vulnerabilities mapped to CVE identifiers and CVSS severity scores.",
        "Goal: Rapid preventative remediation before malicious threat actors can probe."
      ],
      color: '0077B6'
    },
    {
      title: "Penetration Testing (Pen-Test)",
      type: "Simulated Offensive Exploitation",
      focus: "Depth over Breadth",
      points: [
        "Certified ethical hackers simulate real-world Advanced Persistent Threat (APT) attack vectors.",
        "Actively attempts to exploit identified vulnerabilities, chain exploits, and pivot lateral access.",
        "Approaches: Black-box (zero knowledge), Gray-box (partial), White-box (full architectural access).",
        "Goal: Validate whether defensive controls withstand determined, skilled intrusion attempts."
      ],
      color: 'E63946'
    },
    {
      title: "Security Auditing & Metrics",
      type: "Formal Compliance Verification",
      focus: "Process & Evidence Alignment",
      points: [
        "Independent assessment of policies, system logs, configurations against standards (ISO 27001).",
        "Evidence-based verification: Verifies whether policies are actively implemented and documented.",
        "Key Operational Metrics: Mean Time to Detect (MTTD), Mean Time to Respond (MTTR), Patch SLA %.",
        "Goal: Provide executive assurance and fulfill regulatory / external audit requirements."
      ],
      color: '2A9D8F'
    }
  ];

  methods.forEach((m, idx) => {
    const x = 0.6 + idx * 4.1;
    slide.addShape(pres.ShapeType.roundRect, {
      x, y: 1.25, w: 3.9, h: 5.65,
      fill: { color: COLORS.cardBg }, line: { color: COLORS.cardBorder, width: 1.2 }, rectRadius: 0.08
    });

    slide.addShape(pres.ShapeType.rect, {
      x, y: 1.25, w: 3.9, h: 0.12,
      fill: { color: m.color }
    });

    slide.addText(m.title, {
      x: x + 0.2, y: 1.45, w: 3.5, h: 0.45,
      fontSize: 13, bold: true, color: COLORS.textDark, fontFace: 'Calibri'
    });

    slide.addText(`${m.type.toUpperCase()} • ${m.focus}`, {
      x: x + 0.2, y: 1.9, w: 3.5, h: 0.25,
      fontSize: 9.5, bold: true, color: m.color, fontFace: 'Calibri'
    });

    m.points.forEach((pt, pIdx) => {
      slide.addText(`•  ${pt}`, {
        x: x + 0.2, y: 2.3 + pIdx * 1.05, w: 3.5, h: 0.95,
        fontSize: 10.8, color: COLORS.textMuted, fontFace: 'Calibri', lineSpacing: 14
      });
    });
  });
}

// -------------------------------------------------------------
// SLIDE 14: Comprehensive Practical Case Study
// -------------------------------------------------------------
{
  const slide = pres.addSlide();
  slide.background = { color: COLORS.bgLight };
  addHeader(slide, "Applied Case Study: University Online Examination & Grading System", "Real-World Application");

  const caseBoxes = [
    {
      title: "1. Asset & Valuation",
      content: "Central Student Records & Examination Database containing confidential grades, degree records, and student PII.\n• Asset Owner: University Registrar / Controller of Exams.\n• Classification: Highly Confidential (Restricted)."
    },
    {
      title: "2. Threat & Vulnerability",
      content: "Threat Vector: Rogue student / external cyber syndicate attempting SQL injection to alter academic grades or deploy ransomware.\nVulnerability: Outdated PHP framework with unsanitized inputs and lack of Multi-Factor Authentication (MFA) on faculty grading portals."
    },
    {
      title: "3. Risk Evaluation",
      content: "• Likelihood: Moderate (3) | Impact: Critical (5)\n• Qualitative Risk Score: 15 / 25 (High Risk Priority).\n• Financial / Reputational: Massive institutional accreditation revocation and public loss of integrity if grade alterations occur."
    },
    {
      title: "4. Multi-Tier Treatment Plan",
      content: "• Mitigation: Parameterized queries, enforce MFA, deploy Cloudflare WAF, role-based access control.\n• Transfer: Contractual cloud SLA with automated offsite backup guarantees.\n• Acceptance: Low residual risk of authorized faculty password reset latency."
    },
    {
      title: "5. Governance & ISMS Alignment",
      content: "• Policy: University Grading & Data Integrity Policy.\n• Standard: Minimum 16-character passphrases, AES-256 DB encryption.\n• Procedure: Multi-signoff protocol for any manual grade amendment."
    },
    {
      title: "6. Continuous Evaluation",
      content: "• Quarterly external black-box penetration tests before semester exam cycles.\n• Automated weekly vulnerability scanning using OWASP ZAP.\n• Real-time monitoring of failed administrative login spikes."
    }
  ];

  caseBoxes.forEach((cb, idx) => {
    const col = idx % 3;
    const row = Math.floor(idx / 3);
    const x = 0.6 + col * 4.1;
    const y = 1.25 + row * 2.85;

    slide.addShape(pres.ShapeType.roundRect, {
      x, y, w: 3.9, h: 2.65,
      fill: { color: COLORS.cardBg }, line: { color: COLORS.cardBorder, width: 1.2 }, rectRadius: 0.08
    });

    slide.addShape(pres.ShapeType.rect, {
      x, y, w: 3.9, h: 0.35,
      fill: { color: idx < 3 ? COLORS.secondary : COLORS.primary }
    });

    slide.addText(cb.title, {
      x: x + 0.2, y: y + 0.05, w: 3.5, h: 0.28,
      fontSize: 11.5, bold: true, color: COLORS.white, fontFace: 'Calibri'
    });

    slide.addText(cb.content, {
      x: x + 0.2, y: y + 0.45, w: 3.5, h: 2.1,
      fontSize: 10.2, color: COLORS.textDark, fontFace: 'Calibri', lineSpacing: 14
    });
  });
}

// -------------------------------------------------------------
// SLIDE 15: Strategic Takeaways & Summary
// -------------------------------------------------------------
{
  const slide = pres.addSlide();
  slide.background = { color: COLORS.bgLight };
  addHeader(slide, "Summary & Key Takeaways for CLO2", "Executive Summary");

  const takeaways = [
    { num: "1", title: "Assets Precede Defense", text: "You cannot protect what you have not identified, inventoried, and valued. Clear asset ownership is mandatory." },
    { num: "2", title: "Risk is Multi-Dimensional", text: "Risk represents the convergence of threats, vulnerabilities, and business impact—requiring both qualitative speed and quantitative financial precision." },
    { num: "3", title: "Deliberate Treatment", text: "Remediation extends beyond mitigation; organizations must choose among Avoidance, Transference, Mitigation, and Acceptance while managing residual risk." },
    { num: "4", title: "Governance Sets the Tone", text: "Security governance provides strategic direction and accountability; management handles technical implementation and operational execution." },
    { num: "5", title: "ISMS Delivers Repeatability", text: "ISO/IEC 27001 and the Deming PDCA cycle transform ad-hoc firefighting into an auditable, continuously improving security management system." },
    { num: "6", title: "Continuous Verification", text: "Assurance requires constant evaluation through vulnerability assessments, red-team penetration tests, and rigorous independent audits." }
  ];

  takeaways.forEach((t, idx) => {
    const col = idx % 2;
    const row = Math.floor(idx / 2);
    const x = 0.6 + col * 6.2;
    const y = 1.3 + row * 1.85;

    slide.addShape(pres.ShapeType.roundRect, {
      x, y, w: 5.9, h: 1.65,
      fill: { color: COLORS.cardBg }, line: { color: COLORS.cardBorder, width: 1.2 }, rectRadius: 0.08
    });

    slide.addShape(pres.ShapeType.roundRect, {
      x: x + 0.2, y: y + 0.2, w: 0.55, h: 0.55,
      fill: { color: COLORS.secondary }, rectRadius: 0.05
    });

    slide.addText(t.num, {
      x: x + 0.2, y: y + 0.2, w: 0.55, h: 0.55,
      fontSize: 14, bold: true, color: COLORS.white, align: 'center', valign: 'middle'
    });

    slide.addText(t.title, {
      x: x + 0.9, y: y + 0.2, w: 4.8, h: 0.35,
      fontSize: 13, bold: true, color: COLORS.primary, fontFace: 'Calibri'
    });

    slide.addText(t.text, {
      x: x + 0.9, y: y + 0.55, w: 4.8, h: 0.95,
      fontSize: 10.8, color: COLORS.textMuted, fontFace: 'Calibri', lineSpacing: 14
    });
  });
}

// -------------------------------------------------------------
// SLIDE 16: Conclusion & Thank You
// -------------------------------------------------------------
{
  const slide = pres.addSlide();
  slide.background = { color: COLORS.primary };

  slide.addShape(pres.ShapeType.roundRect, {
    x: 2.2, y: 1.2, w: 8.9, h: 4.8,
    fill: { color: '134074' }, line: { color: '0077B6', width: 1.5 }, rectRadius: 0.12
  });

  slide.addText("THANK YOU", {
    x: 2.5, y: 1.6, w: 8.3, h: 0.8,
    fontSize: 40, bold: true, color: COLORS.white, align: 'center', fontFace: 'Calibri'
  });

  slide.addText("Questions & Discussion", {
    x: 2.5, y: 2.45, w: 8.3, h: 0.45,
    fontSize: 18, italic: true, color: '90E0EF', align: 'center', fontFace: 'Calibri'
  });

  slide.addShape(pres.ShapeType.rect, {
    x: 3.5, y: 3.05, w: 6.3, h: 0.05,
    fill: { color: '00B4D8' }
  });

  slide.addText("Presented By:\nShafikul Islam Marwan\nStudent ID: 220121 | Registration No: 2201020\nDepartment of Computer Science & Engineering\nJashore University of Science and Technology (JUST)", {
    x: 2.5, y: 3.3, w: 8.3, h: 1.3,
    fontSize: 13, bold: true, color: 'E0E1DD', align: 'center', fontFace: 'Calibri', lineSpacing: 18
  });

  slide.addText("Presented To: Dr. Engr. Md. Arif Rahman\nAssistant Professor, Department of CSE, JUST", {
    x: 2.5, y: 4.8, w: 8.3, h: 0.7,
    fontSize: 12, italic: true, color: 'CAF0F8', align: 'center', fontFace: 'Calibri', lineSpacing: 16
  });
}

const fs = require('fs');

// Save presentation
const fileName = "CLO2_Computer_Security_Shafikul_Islam_Marwan_220121.pptx";
pres.write({ outputType: 'nodebuffer' })
  .then(buffer => {
    fs.writeFileSync(fileName, buffer);
    console.log(`SUCCESS: Saved presentation as ${fileName} (${buffer.length} bytes)`);
  })
  .catch(err => console.error("ERROR generating presentation:", err));
