<!DOCTYPE html>
<html lang="vi">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Pacific Manpower</title>
    <script src="https://cdn.tailwindcss.com"></script>
    <link rel="preconnect" href="https://fonts.googleapis.com">
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
    <link href="https://fonts.googleapis.com/css2?family=Playfair+Display:wght@400;600;700&family=Plus+Jakarta+Sans:wght@300;400;500;600;700&display=swap" rel="stylesheet">
    <style>
        :root {
            --primary: #005dae;       /* Maritime Blue */
            --primary-light: #3d8fd9; /* Lighter Blue for hovers */
            --accent: #f59e0b;        /* Amber/Gold contrast */
            --accent-hover: #d97706;
            --bg-body: #f8fafc;
            --bg-card: #ffffff;
            --text-main: #0f172a;
            --text-muted: #64748b;
            --border: rgba(0, 93, 174, 0.15);
            --shadow-color: rgba(0, 93, 174, 0.1);
        }

        * {
            margin: 0;
            padding: 0;
            box-sizing: border-box;
        }

        html {
            scroll-behavior: smooth;
        }

        body {
            font-family: 'Plus Jakarta Sans', sans-serif;
            background-color: var(--bg-body);
            color: var(--text-main);
            overflow-x: hidden;
            min-height: 100vh;
        }

        .font-display {
            font-family: 'Playfair Display', serif;
        }

        /* Background Animation */
        .bg-wrapper {
            position: fixed;
            top: 0;
            left: 0;
            width: 100%;
            height: 100%;
            z-index: 0;
            overflow: hidden;
            background: linear-gradient(180deg, #ffffff 0%, #f0f7ff 100%);
        }

        /* Animated Waves */
        .wave-bg {
            position: absolute;
            bottom: 0;
            left: 0;
            width: 200%;
            height: 250px;
            background: url('data:image/svg+xml;utf8,<svg viewBox="0 0 1440 320" xmlns="http://www.w3.org/2000/svg"><path fill="%23005dae" fill-opacity="0.05" d="M0,160L48,176C96,192,192,224,288,213.3C384,203,480,149,576,138.7C672,128,768,160,864,186.7C960,213,1056,235,1152,218.7C1248,203,1344,149,1392,122.7L1440,96L1440,320L1392,320C1344,320,1248,320,1152,320C1056,320,960,320,864,320C768,320,672,320,576,320C480,320,384,320,288,320C192,320,96,320,48,320L0,320Z"></path></svg>');
            background-repeat: repeat-x;
            background-size: 50% 100%;
            animation: waveMove 25s linear infinite;
            opacity: 0.8;
            z-index: 1;
        }

        .wave-bg.wave-2 {
            bottom: 10px;
            opacity: 0.5;
            animation-duration: 30s;
            animation-direction: reverse;
            background: url('data:image/svg+xml;utf8,<svg viewBox="0 0 1440 320" xmlns="http://www.w3.org/2000/svg"><path fill="%23005dae" fill-opacity="0.08" d="M0,224L48,213.3C96,203,192,181,288,181.3C384,181,480,203,576,224C672,245,768,267,864,250.7C960,235,1056,181,1152,165.3C1248,149,1344,171,1392,181.3L1440,192L1440,320L1392,320C1344,320,1248,320,1152,320C1056,320,960,320,864,320C768,320,672,320,576,320C480,320,384,320,288,320C192,320,96,320,48,320L0,320Z"></path></svg>');
            background-size: 50% 100%;
        }

        @keyframes waveMove {
            0% { transform: translateX(0); }
            100% { transform: translateX(-50%); }
        }

        /* Floating Particles (Bubbles) */
        .bubble {
            position: absolute;
            border-radius: 50%;
            background: rgba(0, 93, 174, 0.1);
            animation: floatBubble 15s infinite linear;
            z-index: 1;
        }

        @keyframes floatBubble {
            0% { transform: translateY(100vh) scale(0); opacity: 0; }
            20% { opacity: 0.8; }
            100% { transform: translateY(-100px) scale(1); opacity: 0; }
        }

        /* Main Container */
        .container {
            position: relative;
            z-index: 10;
            min-height: 100vh;
            display: flex;
            flex-direction: column;
        }

        /* Header */
        header {
            padding: 2rem 3rem;
            display: flex;
            justify-content: space-between;
            align-items: center;
        }

        .brand {
            display: flex;
            align-items: center;
            gap: 0.75rem;
        }
        .logo{
            border-radius: 50%;
        }

        .logo-icon {
            width: 40px;
            height: 40px;
            background: var(--primary);
            border-radius: 50%;
            display: flex;
            align-items: center;
            justify-content: center;
            color: #fff;
            box-shadow: 0 4px 12px rgba(0, 93, 174, 0.2);
        }

        .brand-text {
            font-family: 'Playfair Display', serif;
            font-weight: 700;
            font-size: 1.25rem;
            color: var(--primary);
            letter-spacing: -0.02em;
        }

        .status-badge {
            display: inline-flex;
            align-items: center;
            gap: 0.5rem;
            padding: 0.5rem 1rem;
            background: rgba(0, 93, 174, 0.05);
            border: 1px solid var(--border);
            border-radius: 100px;
            font-size: 0.75rem;
            font-weight: 600;
            color: var(--primary);
            text-transform: uppercase;
            letter-spacing: 0.05em;
        }

        .status-dot {
            width: 8px;
            height: 8px;
            background-color: #10b981;
            border-radius: 50%;
            position: relative;
        }

        .status-dot::after {
            content: '';
            position: absolute;
            top: 0; left: 0; width: 100%; height: 100%;
            border-radius: 50%;
            background: #10b981;
            animation: pulse 2s infinite;
        }

        @keyframes pulse {
            0% { transform: scale(1); opacity: 1; }
            100% { transform: scale(2.5); opacity: 0; }
        }

        /* Hero Section */
        .hero {
            flex: 1;
            display: flex;
            flex-direction: column;
            justify-content: center;
            align-items: center;
            text-align: center;
            padding: 2rem;
            max-width: 800px;
            margin: 0 auto;
        }

        .hero-logo-main {
            width: 100px;
            height: 100px;
            background: linear-gradient(135deg, #fff 0%, #f0f7ff 100%);
            border-radius: 50%;
            display: flex;
            align-items: center;
            justify-content: center;
            box-shadow: 
                0 20px 40px rgba(0, 93, 174, 0.15),
                inset 0 0 0 1px rgba(0, 93, 174, 0.1);
            margin-bottom: 2.5rem;
            position: relative;
            animation: float 6s ease-in-out infinite;
        }

        @keyframes float {
            0%, 100% { transform: translateY(0); }
            50% { transform: translateY(-10px); }
        }

        .hero-title {
            font-size: clamp(2rem, 5vw, 3.5rem);
            font-weight: 700;
            color: var(--text-main);
            line-height: 1.2;
            margin-bottom: 0.75rem;
            letter-spacing: -0.02em;
        }

        .hero-title span {
            color: var(--primary);
            display: block;
            font-family: 'Playfair Display', serif;
            font-weight: 600;
        }

        .hero-slogan {
            font-size: 1.125rem;
            color: var(--text-muted);
            margin-bottom: 3rem;
            font-weight: 400;
        }

        /* Action Buttons */
        .actions {
            display: flex;
            flex-direction: column;
            gap: 1.25rem;
            width: 100%;
            max-width: 420px;
        }

        .btn-action {
            display: flex;
            align-items: center;
            justify-content: center;
            gap: 1rem;
            padding: 1.25rem 2rem;
            background: var(--bg-card);
            border-radius: 16px;
            text-decoration: none;
            font-weight: 600;
            font-size: 1rem;
            position: relative;
            overflow: hidden;
            transition: all 0.3s ease;
            border: 1px solid rgba(0, 0, 0, 0.05);
            box-shadow: 0 4px 20px rgba(0, 0, 0, 0.03);
        }

        /* Button Primary (Blue) */
        .btn-primary {
            background: var(--primary);
            color: #fff;
            border-color: transparent;
            box-shadow: 0 8px 24px rgba(0, 93, 174, 0.25);
        }

        .btn-primary:hover {
            background: var(--primary-light);
            transform: translateY(-3px);
            box-shadow: 0 12px 30px rgba(0, 93, 174, 0.35);
        }

        /* Button Secondary (Gold) */
        .btn-secondary {
            color: var(--accent-hover);
            background: #fff;
            border: 1px solid rgba(245, 158, 11, 0.2);
        }
        
        .btn-secondary:hover {
            background: var(--accent);
            color: #fff;
            border-color: transparent;
            transform: translateY(-3px);
            box-shadow: 0 12px 30px rgba(245, 158, 11, 0.3);
        }

        .btn-icon {
            width: 22px;
            height: 22px;
            transition: transform 0.3s ease;
        }

        .btn-action:hover .btn-icon {
            transform: translateX(4px);
        }

        /* Footer */
        footer {
            padding: 2rem;
            text-align: center;
            color: var(--text-muted);
            font-size: 0.85rem;
            position: relative;
            z-index: 10;
        }

        .date-text {
            font-weight: 600;
            color: var(--text-main);
        }

        /* Responsive */
        @media (max-width: 768px) {
            header {
                padding: 1.5rem;
            }
            .hero {
                padding: 1.5rem;
            }
            .hero-logo-main {
                width: 80px;
                height: 80px;
            }
        }
    </style>
</head>
<body>

    <!-- Background -->
    <div class="bg-wrapper">
        <div class="wave-bg"></div>
        <div class="wave-bg wave-2"></div>
        <!-- Generate bubbles via JS or static for simplicity -->
    </div>

    <div class="container">
        <!-- Header -->
        <header>
            <div class="brand">
                <div class="logo-icon">
                    <img src="/sites/all/modules/custom/images/lg.png" class="logo">
                </div>
                <span class="brand-text">Pacific Manpower</span>
            </div>
            
            <div class="status-badge">
                <span class="status-dot"></span>
                Server Online
            </div>
        </header>

        <!-- Hero -->
        <main class="hero">
            <div class="hero-logo-main">
                <svg width="48" height="48" viewBox="0 0 24 24" fill="none" stroke="#005dae" stroke-width="1.5" stroke-linecap="round" stroke-linejoin="round">
                    <path d="M2 20a2 2 0 0 0 2 2h16a2 2 0 0 0 2-2V8l-7 5V8l-7 5V4a2 2 0 0 0-2-2H4a2 2 0 0 0-2 2Z"/>
                    <path d="M17 18h1"/><path d="M12 18h1"/><path d="M7 18h1"/>
                </svg>
            </div>

            <h1 class="hero-title">
                WELCOME TO
                <span>Pacific Manpower</span>
            </h1>
            <p class="hero-slogan">Happier with us</p>

            <div class="actions">
                <!-- Primary Button -->
                <a href="/gui-ho-so" class="btn-action btn-primary">
                    <svg class="btn-icon" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round">
                        <path d="M16 21v-2a4 4 0 0 0-4-4H5a4 4 0 0 0-4 4v2"/>
                        <circle cx="8.5" cy="7" r="4"/>
                        <line x1="20" y1="8" x2="20" y2="14"/>
                        <line x1="23" y1="11" x2="17" y2="11"/>
                    </svg>
                    Gui thong tin thuyen vien
                </a>

                <!-- Secondary Button -->
                <a href="/tuyen-sinh" class="btn-action btn-secondary">
                    <svg class="btn-icon" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round">
                        <path d="M22 10v6M2 10l10-5 10 5-10 5z"/>
                        <path d="M6 12v5c3 3 9 3 12 0v-5"/>
                    </svg>
                    Tuyen sinh khoa cap tau bien
                </a>
            </div>
        </main>

        <!-- Footer -->
        <footer>
            <p>Ngay cap nhat: <span class="date-text" id="currentDate">26 - 03 - 2026</span></p>
        </footer>
    </div>

    <script>
        // Simple bubble generator
        const bgWrapper = document.querySelector('.bg-wrapper');
        const bubbleCount = 10;

        for (let i = 0; i < bubbleCount; i++) {
            const bubble = document.createElement('div');
            bubble.classList.add('bubble');
            const size = Math.random() * 30 + 10 + 'px';
            bubble.style.width = size;
            bubble.style.height = size;
            bubble.style.left = Math.random() * 100 + '%';
            bubble.style.animationDuration = Math.random() * 10 + 15 + 's';
            bubble.style.animationDelay = Math.random() * 10 + 's';
            bgWrapper.appendChild(bubble);
        }

        // Set current date dynamically if needed, or keep static
        // const now = new Date();
        // document.getElementById('currentDate').textContent = now.toLocaleDateString('vi-VN');
    </script>
</body>
</html>